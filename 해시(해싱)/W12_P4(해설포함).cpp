#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define EMPTY 0   // 출석부에 아예 없음 ( = NOITEM 상태 )
#define DROPPED 2  // 출석부에서 삭제된 상태 ( =AVAILABLE 상태. EMPTY 상태와 다르다!)
#define PRESENT 3  // 출석 
#define ABSENT 4  // 결석

// 해시 테이블 1에서 해당 (key, value) 엔트리를 저장했다면, 이에 알맞게 해시 테이블 2에서 (value, key) 엔트리를 저장한다.

struct entry2 {
	int key;  // 이름을 저장. ( <=> entry1 은 학번을 저장)
	int value; // 학번을 저장 ( <=> entry1 은 이름을 저장)
	int valid;
	
	// 인자로 받아온 문자열 key 를 정수형으로 변환시킬떄 활용
	int toInt(string key) {
		int num = 0;
		for (int i = 0; i < key.size(); i++) {
			num = num + (key[i] - 97) * pow(26, i);
		}
		return num;
	}

	entry2() {
		key = 0;
		value = 0;
		valid = EMPTY;
	}

	entry2(string key, int value) {
		this->key = toInt(key);
		this->value = value;
		valid = ABSENT;  // 삽입된 학생은 결석처리 시킴
	}

	void erase() {
		valid = DROPPED;
	}
};

class hashTable2 {
private:
	entry2* table;
	int capacity;
	int divisor;
	int presen; // 현재 출석 상태인 학생의 수
public:
	hashTable2(int N, int M);
	int toInt(string key);
	int hashFnc(int key);
	int hashFnc2(int key);

	void add(string key, int value);
	void remove(string key);
	void present(string key);
	void absent(string key);

	int get_presen(); // 출석 상태인 학생의 수를 리턴
};

hashTable2::hashTable2(int N, int M)
{
	capacity = N;
	table = new entry2[capacity];
	divisor = M;
	presen = 0;
}

int hashTable2::toInt(string key)
{
	int num = 0;
	for (int i = 0; i < key.size(); i++)
	{
		num = num + (key[i] - 97) * pow(26, i);
	}
	return num;
}

int hashTable2::hashFnc(int key)
{
	return key % capacity;
}

int hashTable2::hashFnc2(int key)
{
	return divisor - (key % divisor);
}

void hashTable2::add(string key, int value)
{
	int realKey = toInt(key);
	int index = hashFnc(realKey);
	int probe = 1;

	while (table[index].valid != EMPTY && probe <= capacity)
	{
		// 삽입하려는 학생이 이미 출석부에 존재하는 경우
		if(table[index].valid != DROPPED && (table[index].key == realKey || table[index].value == value)){
			return;
		}
		index = hashFnc(index + hashFnc(realKey));
		probe++;
	}
	if (probe > capacity)
		return;

	table[index] = entry2(key, value);
	return;
}

void hashTable2::remove(string key)
{
	int realKey = toInt(key);
	int index = hashFnc(realKey);
	int probe = 1;

	while (table[index].valid != EMPTY && probe <= capacity) {
		if (table[index].key == realKey && table[index].valid != DROPPED)  // 삭제하려는 학생 엔트리를 찾은 경우
		{
			if (table[index].valid == PRESENT)  // 삭제하려는 학생의 상태가 출석 상태라면
				presen--;   // 출석 상태인 총 학생의 수를 1감소

			table[index].erase();
			return;
		}
		index = hashFnc(index + hashFnc2(realKey));;
		probe++;
	}

	return;
}


void hashTable2::present(string key)
{
	int realKey = toInt(key);
	int index = hashFnc(realKey);
	int probe = 1;

	while (table[index].valid != EMPTY && probe <= capacity) {
		if (table[index].key == realKey && table[index].valid != DROPPED) {   // 원하는 학생 엔트리를 찾은 경우
			if (table[index].valid == ABSENT)
				presen++;  // 출석 상태인 총 학생수 1증가

			table[index].valid = PRESENT;  // 출석 상태로 바꾸고
			cout << table[index].value << '\n';  // 해당 학생의 학번을 출력
			return;
		}
		index = hashFnc(index + hashFnc2(realKey));
		probe++;
	}
	cout << "Invalid" << endl;
	return;
}


void hashTable2::absent(string key)
{
	int realKey = toInt(key);
	int index = hashFnc(realKey);
	int probe = 1;

	while (table[index].valid != EMPTY && probe <= capacity) {
		if (table[index].key == realKey && table[index].valid != DROPPED) {   // 원하는 학생 엔트리를 찾은 경우
			if (table[index].valid == PRESENT)  // 출석상태라면
				presen--;   // 결석상태가 될 것이므로, 출석상태인 총 학생수를 1감소키기고

			table[index].valid == ABSENT;  // 결석처리후
			cout << table[index].value << '\n';  // 해당학생의 학번을 출력
			return;
		}
		index = hashFnc(index + hashFnc2(realKey));
		probe++;
	}

	cout << "Invalid" << endl;
	return;
}

int hashTable2::get_presen()
{
	return presen;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct entry {
	int key;
	string value;
	int valid;
	entry() {
		key = 0;
		value = "";
		valid = EMPTY;
	}
	entry(int key, string value) {
		this->key = key;
		this->value = value;
		valid = ABSENT;
	}

	void erase() {
		valid = DROPPED;
	}
};

class hashTable1 {
private:
	entry* table;
	int capacity;
	int divisor;
public:
	hashTable1(int N, int M);
	int hashFnc(int key);
	int hashFnc2(int key);
	bool add(int key, string value); // true를 리턴하면 hashTable2 에서 add 연산을 진행. => add 하면 안되는데 해버릴수도 있는 상황을 방지
	string remove(int key);   // 삭제한 학생 엔트리의 value (이름) 을 리턴. => 만약 "x" 를 리턴할 경우 hashTable2 에서 remove 연산을 진행하지 않는다.
	void name(int key); 
};


hashTable1::hashTable1(int N, int M)
{
	capacity = N;
	table = new entry[capacity];
	divisor = M;
}

int hashTable1::hashFnc(int key)
{
	return key % capacity;
}

int hashTable1::hashFnc2(int key)
{
	return divisor - (key % capacity);
}

bool hashTable1::add(int key, string value)
{
	int index = hashFnc(key);
	int probe = 1;

	while (table[index].valid != EMPTY && probe <= capacity) {
		// 해당 학생이 이미 존재하는 경우
		if (table[index].valid != DROPPED && (table[index].key == key || table[index].value == value)) {
			return false;
		}
		index = hashFnc(index + hashFnc2(key));
		probe++;
	}

	table[index] = entry(key, value);
	return true;   // 성공적으로 학생 엔트리를 삽입한 경우
}

string hashTable1::remove(int key)
{
	int index = hashFnc(key);
	int probe = 1;

	while (table[index].valid != EMPTY && probe <= capacity) {
		// 삭제하려는 학생 엔트리를 찾은 경우
		if (table[index].valid != DROPPED && table[index].key == key) {
			table[index].erase();   
			return table[index].value;
		}
		index = hashFnc(index + hashFnc2(key));
		probe++;
	}

	return "x";   // 삭제하려는 학생 엔트리가 없는 경우
}

void hashTable1::name(int key)
{
	int index = hashFnc(key);
	int probe = 1;

	while (table[index].valid != EMPTY && probe <= capacity) {
		// 원하는 학생 엔트리를 찾은 경우
		if (table[index].valid != DROPPED && table[index].key == key) {
			cout << table[index].value << '\n';  // 이름 출력
			return;
		}
		index = hashFnc(index + hashFnc2(key));
		probe++;
	}
}

int main(void)
{
	int n;
	cin >> n;

	hashTable1 h1(500000, 7);
	hashTable2 h2(500000, 7);

	while (n--)
	{
		string a;
		cin >> a;
		if (a == "add")
		{
			int key;
			string value;
			cin >> key>> value;
			if(h1.add(key, value))  // h1 에 학생 엔트리 삽입후 h1 의 add 함수로부터 h2 의 add 함수도 호출해도 되는지 판단결과를 얻어온다.
				h2.add(value, key);                      // h2 에도 삽입연산 진행해도 괜찮다면 삽입연산 진행
		}
		else if (a == "delete")
		{
			int key;
			cin >> key;
			string idx = h1.remove(key);
			if (idx != "x")
				h2.remove(idx);
		}
		else if (a == "name")
		{
			int key;
			cin >> key;
			h1.name(key);
		}
		else if (a == "present")
		{
			string value;
			cin >> value;
			h2.present(value);
		}
		else if (a == "absent")
		{
			string value;
			cin >> value;
			h2.absent(value);
		}
	}
	cout << h2.get_presen() << endl;
}
