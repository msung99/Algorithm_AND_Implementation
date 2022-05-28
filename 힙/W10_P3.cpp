#include <iostream>
#include <string>
#include <vector>
using namespace std;

class heap {
private:
	vector<int> arr;
public:
	heap();
	void swap(int idx1, int idx2);
	void upHeap(int idx);
	void downHeap(int idx);

	int size();
	bool empty();
	void insert(int data);
	int max();
	void removeMax();
	void print();
};

heap::heap() {
	arr.push_back(0); 
}

int heap::size() {
	return arr.size() - 1;
}

bool heap::empty() {
	return arr.size() == 1;
}

void heap::swap(int idx1, int idx2) {
	arr[0] = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = arr[0];
}

void heap::insert(int data) {
	arr.push_back(data);
	upHeap(size());
}

void heap::upHeap(int idx) {
	if (idx == 1)
		return;

	int parent = idx / 2;

	if (arr[parent] < arr[idx]) {
		swap(parent, idx);
		upHeap(parent);
	}
}

int heap::max() {
	if (empty())
		return -1;

	return arr[1];
}

void heap::removeMax() {
	if (empty())
	{
		cout << -1 << endl;
		return;
	}

	swap(1, size());
	cout << arr.back() << endl;
	arr.pop_back();
	downHeap(1);
}

void heap::downHeap(int idx) {
	int left = 2 * idx;
	int right = 2 * idx + 1;
	int child;

	if (left > size())
		return;

	else if (left == size())
		child = left;

	else {
		if (arr[left] >= arr[right])
			child = left;
		else
			child = right;
	}

	if (arr[child] > arr[idx])
	{
		swap(child, idx);
		downHeap(child);
	}
}

void heap::print()
{
	if (empty())
	{
		cout << -1 << endl;
		return;
	}

	for (int i = 1; i < arr.size(); i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main(void)
{
	heap h;
	int t;
	cin >> t;
	while (t--)
	{
		string a;
		cin >> a;
		if (a == "insert")
		{
			int data;
			cin >> data;
			h.insert(data);
		}
		else if (a == "size")
		{
			cout << h.size() << endl;
		}
		else if (a == "isEmpty")
		{
			if (h.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (a == "pop")
		{
			h.removeMax();
		}
		else if (a == "top")
		{
			cout << h.max() << endl;
		}
		else if (a == "print")
		{
			h.print();
		}
	}
}
