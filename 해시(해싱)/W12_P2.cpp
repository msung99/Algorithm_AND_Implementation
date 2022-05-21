#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define NOITEM 0  // 로그아웃 상태. 또는 회원가입 아직 안된상태
#define ISITEM 1  // 회원가입은 몰론 현재 로그인까지도 된 상태 
#define AVAILABLE 2 // 회원가입만 된 상태. 현재 로그인은 안된 상태

struct entry {
	int key;
	string value;
	int valid;

	entry() {
		key = 0;
		value = "";
		valid = NOITEM;
	}

	entry(int key, string value) {
		this->key = key;
		this->value = value;
		valid = ISITEM;
	}

	void erase() {
		valid = AVAILABLE;
	}
};

class hashTable {
private:
	entry* table;
	int capacity;
	int hashFnc(int key);
public:
	hashTable(int N);
	void put(int key, string value);
	void erase(int key);
	void find(int key, string value);
	int get_num_key(string key);
};

hashTable::hashTable(int N) {
	capacity = N;
	table = new entry[capacity];
	return;
}

int hashTable::hashFnc(int key) {
	cout << "hashFnc:" << key % capacity << endl;
	return key % capacity;
}

// 회원가입
void hashTable::put(int  key, string value) {
	int index = hashFnc(key);

	// 유저 회원가입이 안되어있다면 회원가입 시도
	if (table[index].valid == NOITEM)
	{
		table[index] = entry(key, value);
		table[index].valid = AVAILABLE; // 회원가입 표식을 남김
		//cout << "put의 submit" << endl;
		cout << "Submit" << endl;
		return;
	}

	// AVAILABLE : 이미 회원가입이 되어있는 상태.
	// ISITEM : 이미 회원가입되있는 것은 몰론, 현재 해당 계정에 대해 로그인까지 되있는 상태 
	else if (table[index].valid == ISITEM || table[index].valid == AVAILABLE)
	{
		//cout << "put의 invalid" << endl;
		cout << "Invalid" << endl;
		return;
	}
}

// 로그아웃
void hashTable::erase(int key) {
	int index = hashFnc(key);
	
	table[index].erase();
		
	//cout << "erase의 submit" << endl;
	cout << "Submit" << endl;
	return;
}

// 로그인 시도하기
void hashTable::find(int key, string value) {

	int index = hashFnc(key);

	// 존재하지 않는 아이디이거나, s의 비밀번호가 일치하지 않는 경우
	if (table[index].valid == NOITEM || table[index].value != value)
	{
		//cout << "find의 invalid" << endl;
		cout << "Invalid" << endl;  // 로그인 실패
		return;
	}

	// 아이디, 비밀번호 쌍이 일치하지만, 해당 아이디가 현재 로그인 상태인 경우
	else if (table[index].valid == ISITEM && table[index].key == key && table[index].value == value)
	{
		//cout << "find의 quit" << endl;
		cout << "Quit" << endl;
		return;
	}

	// 아이디 비밀번호 쌍이 일치하고, 로그아웃된 상태( = AVAILABLE ) 인 경우 
	else if (table[index].valid == AVAILABLE && table[index].key == key && table[index].value == value)
	{
		table[index] = entry(key, value); // 로그인 요청을 승인한다.
		
		//cout << "find의 submit" << endl;
		cout << "Submit" << endl;
		return;
	}
}

// 주어진 문자열을 26진법으로 변환
int hashTable::get_num_key(string key) {
	int count = 0;
	int multi = 1;

	for (int i = 0; key[i]; ++i)
	{
		count += (key[i] - 'a') * multi;
		multi = multi * 26;
	}
	return count;
}

int main(void)
{
	hashTable h(200003);
	int t;
	cin >> t;
	while (t--)
	{
		string command;
		cin >> command;

		if (command == "signup")
		{
			string id, password;
			cin >> id >> password;
			int my_id = h.get_num_key(id);
			h.put(my_id, password);
		}
		else if (command == "login")
		{
			string id, password;
			cin >> id >> password;
			int my_id = h.get_num_key(id);
			h.find(my_id, password);
		}
		else if (command == "logout")
		{
			string id;
			cin >> id;
			int my_id = h.get_num_key(id);
			h.erase(my_id);
		}
	}
}