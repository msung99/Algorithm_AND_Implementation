// ÀÌ ¹®Á¦´Â key, value °ªÀ¸·Î ¸ğµÎ ÇØ½ÌÀ» ÇÏ´Â ÇØ½ÃÅ×ÀÌºíÀÌ´Ù.
// key °ªÀº Á¤¼öÇü, Áï ¼ıÀÚ¶ó¼­ ¹®Á¦°¡ ¾ø´Ù. ÇÏÁö¸¸ value ´Â ¹®ÀÚ¿­ÀÌ¹Ç·Î 26Áø¹ıÀ¸·Î º¯È¯ÇØÁÖµµ·Ï ÇÑ´Ù.

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define EMPTY 0  // Ãâ¼®ºÎ ¸í´Ü¿¡ ¾ø´Â °æ¿ì
#define CHECK 1 // Ãâ¼®ºÎ ¸í´Ü¿¡ ÀÖÀ¸¸ç, Ãâ¼® »óÅÂÀÎ °æ¿ì
#define NOCHECK 2 // Ãâ¼®ºÎ ¸í´Ü¿¡ ÀÖÀ¸¸ç, °á¼® »óÅÂÀÎ °æ¿ì
#define AVAILABLE 3     // Ãâ¼®ºÎ ¸í´Ü¿¡ ÀÖÀ½. Ãâ¼® ¹× °á¼® »óÅÂ´Â ¾ÆÁ÷ °áÁ¤µÇÁö ¾ÊÀ½.

struct entry {
	int key;
	int trans_value; // 26Áø¹ıÀ¸·Î º¯È¯µÈ value °ª
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
		valid = NOCHECK;   // Ãâ¼®ºÎ ¸í´Ü¿¡ ¿Ã¶ó°¡ÀÖ´Â »óÅÂ
	}
	void erase() {
		valid = AVAILABLE; // °á¼® »óÅÂ·Î Ã³¸®
	}
};


// 1. key °ªÀ» ÇØ½ÌÇØ¼­ Å½»ö,»ğÀÔ,»èÁ¦¸¦ ÁøÇàÇÏ´Â ÇØ½ÃÅ×ÀÌºí
class hashTable1 {
private:
	entry* table;
	int capacity;
	int divisor;
public:
	hashTable1(int N, int M);
	int hashFunc(int key);
	int hashFunc2(int key);

	void add(int key, string value); // Ãú¼®ºÎ¿¡ (key, value) ¿£Æ®¸® ÇĞ»ıÀ» µî·Ï
	string delection(int key);  // ÇĞ¹øÀÌ key ÀÎ ÇĞ»ıÀ» Ãâ¼®ºÎ¿¡¼­ »èÁ¦
	void name(int key);  // ÇĞ¹ø¿¡ key ÀÎ ÇĞ»ıÀÇ ÀÌ¸§(value) ¸¦ Ãâ·Â

	void make_present(int key); // hashTable2 ÀÇ present, absent ÇÔ¼ö¸¦ È£ÃâÇØ¼­ ÇØ´ç ÇĞ»ı(¿£Æ®¸®)ÀÇ Ãâ¼® ¹× °á¼® ¿©ºÎ¸¦ hashTable1¿¡¼­µµ º¯°æÇØ¾ß ÇÏ´Â°æ¿ì
	void make_absent(int key);
};

hashTable1::hashTable1(int N, int M) {
	divisor = M;
	capacity = N;
	table = new entry[capacity];
}

// 1Â÷ ÇØ½ÃÇÔ¼ö
int hashTable1::hashFunc(int key) {
	return key % capacity;
}

// 2Â÷ ÇØ½ÃÇÔ¼ö
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
			return table[index].value;  // »èÁ¦ÇÑ ¿£Æ®¸®ÀÇ value ¸¦ ¸®ÅÏ. ¸®ÅÏµÈ value ¸¦ hashTable2 ¿¡¼­ È°¿ëÇÑ´Ù. Áï, hashTable2 ÀÇ ¿£Æ®¸®¸¦ »èÁ¦ÇÒ‹š È°¿ë
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

// ÁÖ¾îÁø key ¿¡ ÇØ´çÇÏ´Â ¿£Æ®¸®(ÇĞ»ı)¸¦ Ãâ¼® »óÅÂ·Î º¯°æ
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
			table[index].valid = CHECK; // Ãâ¼® 
			return;
		}
		index = hashFunc(index + hashFunc2(key));
		probe++;
	}
}

// ÁÖ¾îÁø key ¿¡ ÇØ´çÇÏ´Â ¿£Æ®¸®(ÇĞ»ı)¸¦ °á¼® »óÅÂ·Î º¯°æ
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
			table[index].valid = NOCHECK; // °á¼® 
			return;
		}
		index = hashFunc(index + hashFunc2(key));
		probe++;
	}
}


// 2. value °ªÀ» ÇØ½ÌÇØ¼­ Å½»ö, »ğÀÔ, »èÁ¦¸¦ ÁøÇàÇÏ´Â ÇØ½ÃÅ×ÀÌºí

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
	void add(int key, string value); // Ãú¼®ºÎ¿¡ (key, value) ¿£Æ®¸® ÇĞ»ıÀ» µî·Ï
	void delection(string value);
	int present(string value);
	int absent(string value);
};

hashTable2::hashTable2(int N, int M) {
	divisor = M;
	capacity = N;
	table = new entry[capacity];
}

// 1Â÷ ÇØ½ÃÇÔ¼ö
int hashTable2::hashFunc(int key) {
	return key % capacity;
}

// 2Â÷ ÇØ½ÃÇÔ¼ö
int hashTable2::hashFunc2(int key) {
	return divisor - (key % divisor);
}

// ÇØ´ç ¹®ÀÚ¿­À» 26Áø¹ıÀ¸·Î º¯È¯
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

	// »èÁ¦ÇÒ key °ª ÇØ½ÃÅ×ÀÌºí¿¡¼­ Ã£¾Æ³»±â(Å½»ö)
	while (table[index].valid != EMPTY && probe <= capacity) {
		if (table[index].valid != EMPTY && table[index].value == value) // »èÁ¦ÇÒ ¿£Æ®¸®¸¦ Ã£¾Æ³½ °æ¿ì 
		{
			table[index].valid = EMPTY; // EMPTY Ã³¸®(= ­„¼®ºÎ ¸í´Ü¿¡¼­ »èÁ¦)
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
			table[index].valid = CHECK; // Ãâ¼® »óÅÂ·Î º¯°æÈÄ
			cout << table[index].key << endl; // ÇØ´ç ÇĞ»ıÀÇ ÇĞ¹øÀ» Ãâ·Â
			return table[index].key;  // ¸®ÅÏµÈ key ´Â hashTable ÀÇ µ¿ÀÏÇÑ ¿£Æ®¸®¸¦ Ãâ¼® Ã³¸®ÇÏ±â À§ÇØ È°¿ë
		}
		index = hashFunc(index + hashFunc2(realValue));
		probe++;
	}

	cout << "Invalid" << endl;  // Ãâ¼®ºÎ¿¡ Á¸ÀçÇÏÁö ¾ÊÀ» °æ¿ì
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
				return table[index].key; // ¸®ÅÏµÈ key ´Â hashTable ÀÇ µ¿ÀÏÇÑ ¿£Æ®¸®¸¦ Ãâ¼® Ã³¸®ÇÏ±â À§ÇØ È°¿ë
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