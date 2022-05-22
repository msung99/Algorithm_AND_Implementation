#include <iostream>
#include <cmath>
using namespace std;

#define EMPTY 0
#define DROPPED 2
#define PRESENT 3
#define ABSENT 4
struct entry2 {
	int key;
	int value;
	int valid;

	int toInt(string key) {
		int k = 0;
		for (int i = 0; i < key.size(); i++) {
			k += (key[i] - 97) * pow(26, i);
		}
		return k;
	}
	entry2() {
		key = 0;
		value = 0;
		valid = EMPTY;
	}
	entry2(string k, int value) {
		key = toInt(k);
		this->value = value;
		valid = ABSENT;
	}
	void erase() {
		valid = DROPPED;
	}
};

class HT2 {
private:
	entry2* table;
	int capacity;
	int devisior;
	int presen;
	int toInt(string key) {
		int k = 0;
		for (int i = 0; i < key.size(); i++) {
			k += (key[i] - 97) * pow(26, i);
		}
		return k;
	}
	int hashFunc(int key) {
		return key % capacity;
	}
	int hashFunc2(int key) {
		return devisior - (key % devisior);
	}

public:
	HT2(int size, int d) {
		capacity = size;
		table = new entry2[capacity];
		devisior = d;
		presen = 0;
	}
	void add(string k, int v) {
		int realKey = toInt(k);
		int index = hashFunc(realKey);
		int probe = 1;


		while ((table[index].valid != EMPTY && probe <= capacity)) {
			if (table[index].valid != DROPPED && (table[index].key == realKey || table[index].value == v)) {
				return;
			}
			index = hashFunc(index + hashFunc2(realKey));
			probe++;
		}
		if (probe > capacity)
			return;
		table[index] = entry2(k, v);

		return;
	}
	void remove(string k) {
		int realKey = toInt(k);
		int index = hashFunc(realKey);
		int probe = 1;

		while (table[index].valid != EMPTY && probe <= capacity) {
			if (table[index].key == realKey && table[index].valid != DROPPED) {
				if (table[index].valid == PRESENT)
					presen--;
				table[index].erase();
	
				return;
			}
			index = hashFunc(index + hashFunc2(realKey));
			probe++;
		}
		return;
	}
	
	void present(string k) {
		int realKey = toInt(k);
		int index = hashFunc(realKey);
		int probe = 1;

		while (table[index].valid != EMPTY && probe <= capacity) {
			if (table[index].key == realKey && table[index].valid != DROPPED) {
				if (table[index].valid == ABSENT)
					presen++;
				table[index].valid = PRESENT;
				cout << table[index].value << "\n";
				return;
			}
			index = hashFunc(index + hashFunc2(realKey));
			probe++;
		}
		cout << "Invalid\n";
		return;
	}
	void absent(string k) {
		int realKey = toInt(k);
		int index = hashFunc(realKey);
		int probe = 1;

		while (table[index].valid != EMPTY && probe <= capacity) {
			if (table[index].key == realKey && table[index].valid != DROPPED) {
				if (table[index].valid == PRESENT)
					presen--;
				table[index].valid = ABSENT;
				cout << table[index].value << "\n";
				return;
			}
			index = hashFunc(index + hashFunc2(realKey));
			probe++;
		}
		cout << "Invalid\n";
		return;

	}
	int getPresent() { return presen; }
};
struct entry {
	int key;
	string value;
	int valid;

	entry() {
		key = 0;
		value = "";
		valid = EMPTY;
	}
	entry(int k, string v) {
		key = k;
		value = v;
		valid = ABSENT;
	}
	void erase() {
		valid = DROPPED;
	}
};

class HT {
private:
	entry* table;
	int capacity;
	int devisior;
	int hashFunc(int key) {
		return key % capacity;
	}
	int hashFunc2(int key) {
		return devisior - (key % devisior);
	}

public:
	HT(int size, int d) {
		capacity = size;
		table = new entry[capacity];
		devisior = d;
	}
	bool add(int k, string v) {
		int index = hashFunc(k);
		int probe = 1;

	
		while ((table[index].valid != EMPTY && probe <= capacity)) {
			if (table[index].valid != DROPPED && (table[index].key == k || table[index].value == v)) {
				return false;
			}
			index = hashFunc(index + hashFunc2(k));
			probe++;
		}
		if (probe > capacity)
			return false;
		table[index] = entry(k, v);
		return true;
	}
	string remove(int k) {
		int index = hashFunc(k);
		int probe = 1;

		while (table[index].valid != EMPTY && probe <= capacity) {
			if (table[index].key == k && table[index].valid != DROPPED) {
				table[index].erase();
				return table[index].value;
			}
			index = hashFunc(index + hashFunc2(k));
			probe++;
		}
		return "x";
	}
	void name(int k) {
		int index = hashFunc(k);
		int probe = 1;

		while (table[index].valid != EMPTY && probe <= capacity) {
			if (table[index].valid != DROPPED && table[index].key == k) {
				cout << table[index].value << "\n";
				return;
			}
			index = hashFunc(index + hashFunc2(k));
			probe++;
		}
	}
	
};

int main() {
	int n;
	cin >> n;

	string in, value;
	int key;
	HT t{ 500000, 7 };
	HT2 t2{ 500000, 7 };
	for (int i = 0; i < n; i++) {
		cin >> in;
		if (in == "add") {
			cin >> key >> value;
			if (t.add(key, value)) {
				t2.add(value, key);
			}
			
		}
		else if (in == "delete") {
			cin >> key;
			string idx = t.remove(key);
			if (idx != "x")
				t2.remove(idx);
			
		}
		else if (in == "name") {
			cin >> key;
			t.name(key);
		}
		else if (in == "present") {
			cin >> value;
			t2.present(value);
		}
		else if (in == "absent") {
			cin >> value;
			t2.absent(value);
		}
	}
	cout << t2.getPresent() << endl;

}