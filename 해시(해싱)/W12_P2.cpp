#include <iostream>
#include <cmath>
#define EMPTY 0   // 회원가입 자체도 진행하지 않은 경우. 즉, 해당 셀이 비어있는 경우
#define LOGIN 1   // 회원가입은 몰론 로그인까지 한 경우
#define LOGOUT 2  // 회원가입은 했으나, 로그아웃 상태인 경우
#define SIGNED 3  // 회원가입만 
using namespace std;

struct entry {
	int key;
	string value;
	int valid;

	entry() {
		key = 0;
		value = "";
		valid = EMPTY;
	}

	// 주어진 문자열을 26진수로 변환
	int tolnt(string key) {
		int num = 0;
		for (int i = 0; i < key.length(); i++) {
			num = num + (key[i] - 97) * pow(26, i);
		}
		return num;
	}

	entry(string key, string value) {
		this->key = tolnt(key);
		this->value = value;
		valid = SIGNED;
	}

	void erase() {
		valid = LOGOUT;
	}
};

class hashTable {
private:
	entry* table;
	int capacity;
	int divisor;
public:
	hashTable(int N, int M);
	int hashFunc(int key);
	int hashFunc2(int key);
	int toInt(string key);
	void signUp(string key, string value);
	void logout(string key);
	void login(string key, string value);
};

hashTable::hashTable(int N, int M) {
	divisor = M;
	capacity = N;
	table = new entry[capacity];
}

// 1차 해시함수
int hashTable::hashFunc(int key) {
	return key % capacity;
}

// 2차 해시함수
int hashTable::hashFunc2(int key) {
	return divisor - (key % divisor);
}

// 주어진 문자열을 26진수로 변환
int hashTable::toInt(string key) {
	int num = 0;
	for (int i = 0; i < key.length(); i++) {
		num += static_cast<int>((key[i] - 97)) * pow(26, i);
	}
	return num;
}

// 회원가입
void hashTable::signUp(string key, string value) {
	int realKey = toInt(key);  // // 우리가 찾아야할 엔트리의 key (= 찾아야할 회원의 아이디). 26진수로 변형된 key 값
	int index = hashFunc(realKey);
	int probe = 1;

	// 빈자리를 찾아서 탐색해 나감. 탐색이 끝나고 찾아낸 빈자리에 엔트릴 삽입한다.
	while (table[index].valid != EMPTY && probe <= capacity) {
		if (table[index].key == realKey) // 이미 회원가입된 아이디인 경우. 즉, key 값을 가지는 엔트리가 이미 배열에 존재하는 경우
		{
			cout << "Invalid" << endl;  // 이미 회원가입 되있으니까, 회원가입 하지 않고 종료
			return;
		}
		index = hashFunc(index + hashFunc2(realKey)); // 이중 해싱을 활용해 충돌 관리
		probe++;
	}
	if (probe > capacity)
		return;

	// 회원가입 시도
	table[index] = entry(key, value); // 탐색 과정을 통해 찾아낸 빈자리에 엔트리를 삽입 
	cout << "Submit" << endl;
	return;
}

// 로그아웃 => 주어진 key 값을 아이디로 가지는 회원을 찾아내서 로그아웃 시킨다.
void hashTable::logout(string key) {
	int realKey = toInt(key); // 우리가 찾아야할 엔트리의 key (= 찾아야할 회원의 아이디)
	int index = hashFunc(realKey);
	int probe = 1;

	// 탐색하는 해당 셀의 엔트리가 이전에 데이터가 저장되어 있던 엔트리였거나(= 회원가입o, 로그인x), 엔트리가 저장되어 있는 경우(= 회원가입o, 로그인o) 에 탐색을 지속
	while (table[index].valid != EMPTY && probe <= capacity) {
		if (table[index].key == realKey && table[index].valid == LOGIN) // 로그아웃을 해야할 대상을 찾은 경우 
		{
			table[index].erase();  // 로그아웃
			cout << "Submit" << endl;
			return;
		}
		index = hashFunc(index + hashFunc2(realKey)); // 이중 해시를 활용해 충돌을 방지하면서 로그아웃을 시킬 다움 대상을 탐색해 나감
		probe++;
	}
	return;
}

void hashTable::login(string key, string value) {
	int realKey = toInt(key);
	int index = hashFunc(realKey);
	int probe = 1;
	while (table[index].valid != EMPTY && probe <= capacity) {

		// 아이디와 비밀번호과 일치하지만, 해당 계정이 이미 로그인 되어있는 상태인 경우
		if (table[index].valid == LOGIN && table[index].key == realKey && table[index].value == value) {
			cout << "Quit" << endl;
			return;
		}

		// 아이디와 비밀번호 쌍이 일치하고, 해당 계정이 현재 로그아웃 된 상태인 경우
		else if ((table[index].valid == LOGOUT || table[index].valid == SIGNED) && table[index].key == realKey && table[index].value == value) {
			table[index].valid = LOGIN;
			cout << "Submit" << endl;
			return;
		}

		// 비밀번호가 일치하지 않는 경우
		else if (table[index].key == realKey && table[index].value != value) {

			cout << "Invalid" << endl;
			return;
		}
		index = hashFunc((index + hashFunc2(realKey))); //capacity를 넘어가면 원형으로 만들어주기 위함이다.

		probe++;
	}

	// 존재하지 않는 계정(아이디)인 경우
	cout << "Invalid" << endl;
	return;
}

int main() {
	int a;
	cin >> a;
	hashTable t{ 200000, 7 };

	string in;
	string x;
	string y;
	for (int i = 0; i < a; i++) {
		cin >> in;
		if (in == "signup") {
			cin >> x >> y;
			t.signUp(x, y);
		}
		else if (in == "login") {
			cin >> x >> y;
			t.login(x, y);
		}
		else if (in == "logout") {
			cin >> x;
			t.logout(x);
		}

	}
}