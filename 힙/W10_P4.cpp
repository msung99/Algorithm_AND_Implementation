#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class heap {
private:
	vector<int> arr;
	void swap(int idx1, int idx2);
	void upHeap(int idx);
	void downHeap(int idx);
public:
	heap();
	int size();
	bool empty();
	void insert(int data);
	int min();
	void removeMin();
	void print(int p, int count);
	void make_and_insert();
};

heap::heap() {
	arr.push_back(0);
}

int heap::size() {
	return arr.size() - 1;
}

bool heap::empty() {
	return (arr.size() == 1);
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
	if (arr[parent] > arr[idx]) {
		swap(parent, idx);
		upHeap(parent);
	}
}

int heap::min()
{
	if (empty())
		return -1;

	return arr[1];
}

void heap::removeMin()
{
	swap(1, size());
	arr.pop_back();

	downHeap(1);
}

void heap::downHeap(int idx) {
	int left = 2 * idx;
	int right = 2 * idx + 1;
	int child;

	if (left > size()) {
		return;
	}

	else if (left == size()) {
		child = left;
	}

	else {
		if (arr[left] > arr[right])
			child = right;
		else
			child = left;
	}

	if (arr[child] < arr[idx]) {
		swap(child, idx);
		downHeap(child);
	}
}

void heap::make_and_insert()
{
	vector<int> new_list;

	// 상위 3개의 온도를 가진 물질 추출
	new_list.push_back(min());
	removeMin();
	new_list.push_back(min());
	removeMin();
	new_list.push_back(min());
	removeMin();

	sort(new_list.begin(), new_list.end());
	int result = (new_list[0] + new_list[2]) / 2; // 새로운 물질 생성

	insert(result); // 새로운 물질 힙에 추가 
}

void heap::print(int p, int count)
{
	if (empty())
	{
		cout << -1 << endl;
		return;
	}

	// 만일 합성 과정중에 힙 내에 물질이 2개 이하가 되었음에도 불구하고, 
	// 아직 힙의 물질중에 p 이하의 온도를 가진 물질이 있다면 모든 물질의 온도를 p 이하로 만드는데 실패한 것이다/
	if (size() <= 2 && min() < p)
	{
		cout << "False" << endl;
		return;
	}

	cout << count << endl;
	for (int i = 1; i < arr.size(); i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		heap h;
		int n, p;
		cin >> n >> p;

		for (int i = 0; i < n; i++)
		{
			int data;
			cin >> data;
			h.insert(data);
		}

		int count = 0;
		while (h.size() >= 3 && h.min() < p)
		{
			h.make_and_insert();
			count++;
		}
		h.print(p, count);
	}
}