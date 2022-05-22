// 이 문제는 key, value 값으로 모두 해싱을 하는 해시테이블이다.
// key 값은 정수형, 즉 숫자라서 문제가 없다. 하지만 value 는 문자열이므로 26진법으로 변환해주도록 한다.

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define EMPTY 0  // 출석부 명단에 없는 경우
#define CHECK 1 // 출석부 명단에 있으며, 출석 상태인 경우
#define NOCHECK 2 // 출석부 명단에 있으며, 결석 상태인 경우
#define AVAILABLE 3     // 출석부 명단에 있음. 출석 및 결석 상태는 아직 결정되지 않음.

struct entry {
	int key;
	int trans_value; // 26진법으로 변환된 value 값
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
		valid = NOCHECK;   // 출석부 명단에 올라가있는 상태
	}
	void erase() {
		valid = AVAILABLE; // 결석 상태로 처리
	}
};


// 1. key 값을 해싱해서 탐색,삽입,삭제를 진행하는 해시테이블
class hashTable1 {
private:
	entry* table;
	int capacity;
	int divisor;
public:
	hashTable1(int N, int M);
	int hashFunc(int key);
	int hashFunc2(int key);

	void add(int key, string value); // 츨석부에 (key, value) 엔트리 학생을 등록
	string delection(int key);  // 학번이 key 인 학생을 출석부에서 삭제
	void name(int key);  // 학번에 key 인 학생의 이름(value) 를 출력

	void make_present(int key); // hashTable2 의 present, absent 함수를 호출해서 해당 학생(엔트리)의 출석 및 결석 여부를 hashTable1에서도 변경해야 하는경우
	void make_absent(int key);
};

hashTable1::hashTable1(int N, int M) {
	divisor = M;
	capacity = N;
	table = new entry[capacity];
}

// 1차 해시함수
int hashTable1::hashFunc(int key) {
	return key % capacity;
}

// 2차 해시함수
int hashTable1::hashFunc2(int key) {
	return divisor - (key % divisor);
}

void hashTable1::add(int key, string value){
	int index = hashFunc(key);
	int probe = 1;

	while (table[index].valid != EMPTY && probe <= capacity) {
		index = hashFunc(index + hashFunc2(key));
		probe++;
	}

	if (probe > capacity)
		return;

	table[index] = entry(key, value);
	return;
}

string hashTable1::delection(int key) {
	int index = hashFunc(key);
	int probe = 1;

	// cout << "table[index].vaild : " << table[index].valid << endl;

	while (table[index].valid != EMPTY && probe <= capacity) {
		if (table[index].valid != EMPTY && table[index].key == key)
		{
			table[index].erase();
			return table[index].value;  // 삭제한 엔트리의 value 를 리턴. 리턴된 value 를 hashTable2 에서 활용한다. 즉, hashTable2 의 엔트리를 삭제할 활용
		}
		index = hashFunc(index + hashFunc2(key));
		probe++;
	}

	return "";
}

void hashTable1::name(int key) {
	int index = hashFunc(key);
	int probe = 1;

	while (table[index].valid != EMPTY && probe <= capacity)
	{
		if (table[index].valid != EMPTY && table[index].key == key)
		{
			cout << table[index].value << endl;
			return;
		}
		index = hashFunc(index + hashFunc2(key));
		probe++;
	}
}

// 주어진 key 에 해당하는 엔트리(학생)를 출석 상태로 변경
void hashTable1::make_present(int key)
{
	if (key == -1)
		return;

	int index = hashFunc(key);
	int probe = 1;

	while (table[index].valid != EMPTY && probe <= capacity)
	{
		if (table[index].valid != EMPTY && table[index].key == key)
		{
			table[index].valid = CHECK; // 출석 
			return;
		}
		index = hashFunc(index + hashFunc2(key));
		probe++;
	}
}

// 주어진 key 에 해당하는 엔트리(학생)를 결석 상태로 변경
void hashTable1::make_absent(int key)
{
	if (key == -1)
		return;

	int index = hashFunc(key);
	int probe = 1;

	while (table[index].valid != EMPTY && probe <= capacity)
	{
		if (table[index].valid != EMPTY && table[index].key == key)
		{
			table[index].valid = NOCHECK; // 결석 
			return;
		}
		index = hashFunc(index + hashFunc2(key));
		probe++;
	}
}


// 2. value 값을 해싱해서 탐색, 삽입, 삭제를 진행하는 해시테이블

class hashTable2 {
private:
	entry* table;
	int capacity;
	int divisor;
public:
	hashTable2(int N, int M);
	int hashFunc(int key);
	int hashFunc2(int key);

	int toInt(string key);
	void add(int key, string value); // 츨석부에 (key, value) 엔트리 학생을 등록
	void delection(string value);
	int present(string value);
	int absent(string value);
};

hashTable2::hashTable2(int N, int M) {
	divisor = M;
	capacity = N;
	table = new entry[capacity];
}

// 1차 해시함수
int hashTable2::hashFunc(int key) {
	return key % capacity;
}

// 2차 해시함수
int hashTable2::hashFunc2(int key) {
	return divisor - (key % divisor);
}

// 해당 문자열을 26진법으로 변환
int hashTable2::toInt(string key) {
	int num = 0;
	for (int i = 0; i < key.length(); i++) {
		num += int(key[i] - 97) * pow(26, i);
	}
	//  
	return num;
}

void hashTable2::add(int key, string value) {
	int rearValue = toInt(value);
	int index = hashFunc(rearValue);
	int probe = 1;

	while (table[index].valid != EMPTY && probe <= capacity) {
		index = hashFunc(index + hashFunc2(rearValue));
		probe++;
	}

	if (probe > capacity)
		return;

	table[index] = entry(key, value);
	return;
}

void hashTable2::delection(string value)
{
	int rearValue = toInt(value);
	int index = hashFunc(rearValue);
	int probe = 1;

	// 삭제할 key 값 해시테이블에서 찾아내기(탐색)
	while (table[index].valid != EMPTY && probe <= capacity) {
		if (table[index].valid != EMPTY && table[index].value == value) // 삭제할 엔트리를 찾아낸 경우 
		{
			table[index].valid = EMPTY; // EMPTY 처리(= 석부 명단에서 삭제)
			return;
		}
		index = hashFunc(index + hashFunc2(rearValue));
		probe++;
	}
	return;
}

int hashTable2::present(string value) {
	int realValue = toInt(value);
	int index = hashFunc(realValue);
	int probe = 1;

	while (table[index].valid != EMPTY && probe <= capacity)
	{
		if (table[index].value == value && table[index].valid != EMPTY)
		{
			table[index].valid = CHECK; // 출석 상태로 변경후
			cout << table[index].key << endl; // 해당 학생의 학번을 출력
			return table[index].key;  // 리턴된 key 는 hashTable 의 동일한 엔트리를 출석 처리하기 위해 활용
		}
		index = hashFunc(index + hashFunc2(realValue));
		probe++;
	}

	cout << "Invalid" << endl;  // 출석부에 존재하지 않을 경우
	return -1;
}

int hashTable2::absent(string value)
{
	int realValue = toInt(value);
	int index = hashFunc(realValue);
	int probe = 1;

	while (table[index].valid != EMPTY && probe <= capacity)
	{
		if (table[index].value == value && table[index].valid != EMPTY)
		{
			if (table[index].value == value && table[index].valid != EMPTY)
			{
				table[index].valid = NOCHECK;
				cout << table[index].key << endl;
				return table[index].key; // 리턴된 key 는 hashTable 의 동일한 엔트리를 출석 처리하기 위해 활용
			}
			index = hashFunc(index + hashFunc2(realValue));
			probe++;
		}
	}
	cout << "Invalid" << endl;
	return -1;
}

int main(void)
{
	int t;
	cin >> t;
	hashTable1 h1(500000, 13);
	hashTable2 h2(500000, 13);

	while (t--)
	{
		string a;
		cin >> a;
		if (a == "add")
		{
			int x;
			string s;
			cin >> x >> s;
			h1.add(x, s);
			h2.add(x, s);
		}
		else if (a == "delete")
		{
			int x;
			cin >> x;
			string value = h1.delection(x);
			h2.delection(value);
		}
		else if (a == "name")
		{
			int x;
			cin >> x;
			h1.name(x);
		}
		else if (a == "present")
		{
			string s;
			cin >> s;
			int key = h2.present(s);
			h1.make_present(key);
		}
		else if (a == "absent")
		{
			string s;
			cin >> s;
			int key = h2.absent(s);
			h1.make_absent(key);
		}
	}
}
