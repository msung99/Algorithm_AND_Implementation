#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 배열(벡터) 기반 최대힙 
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

	// minHeap 과 다른 내용 :  자신의 직계 부모보다 자신의 key 값이 더 "클때까지" 계속 upHeap 을 수행
	int parent = idx / 2;
	if (arr[parent] < arr[idx]) {
		swap(parent, idx);
		upHeap(parent);
	}
}

int heap::max()
{
	if (empty())
		return -1;

	return arr[1];
}


void heap::removeMax()
{
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

	
	if (left > size()) {
		return;
	}

	else if (left == size()) {
		child = left;
	}

	// minHeap 과 다른 내용 : 두 자식중 더 "큰 자식"을 찾아낸다.
	else {
		if (arr[left] <= arr[right])
			child = right;
		else
			child = left;
	}

	if (arr[child] > arr[idx]) {  // minHeap과 다른 내용 : 자신이 자식 key 값 보다 더 "작아서" downHeap 을 진행해야 하는 경우
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