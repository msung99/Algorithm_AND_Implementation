#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<int> list;
		vector<int> list2;
		int n;
		cin >> n;
		while (n--)
		{
			int data;
			cin >> data;
			list.push_back(data);
		}
		sort(list.rbegin(), list.rend());
		for (int i = 0; i < list.size(); i++) {
			if (list[i] % 2 == 0)
				list2.push_back(list[i]);
			else
				cout << list[i] << ' ';
		}

		for (int i = 0; i <list2.size(); i++)
		{
			cout << list2[i] << ' ';
		}
		cout << endl;
	}
}

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// min PQ 를 가정 
struct compare {
	bool operator()(const int& p, const int& q) const {
		return p < q;
	}
};

class sortedSeqPQ {
private:
	vector<int> seq;
public:
	int size();
	bool empty();
	void insert(int data);
	void print();
};

int sortedSeqPQ::size() {
	return seq.size();
}

bool sortedSeqPQ::empty() {
	return seq.size() == 0;
}

void sortedSeqPQ::insert(int data) {
	compare C;
	int idx = 0;

	for (idx = 0; idx < seq.size(); idx++) {
		if (C(seq[idx], data))
			break;
	}

	seq.insert(seq.begin() + idx, data);
}


void sortedSeqPQ::print() {
	vector<int> list;

	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] % 2 == 0) {
			list.push_back(seq[i]);
		}
		else {
			cout << seq[i] << ' ';
		}
	}

	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << ' ';
	}
	cout << endl;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		sortedSeqPQ q;
		int n;
		cin >> n;
		while (n--)
		{
			int data;
			cin >> data;
			q.insert(data);
		}
		q.print();
	}
}
*/
