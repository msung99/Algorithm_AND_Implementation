#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

void heap::print(int p, int count)
{
	if (empty())
	{
		cout << -1 << endl;
		return;
	}

	// 만일 합성 과정중에 힙 내에 물질이 2개 이하가 되었음에도 불구하고, 
	// 아직 힙의 물질중에 p 이상의 온도를 가진 물질이 있다면 모든 물질의 온도를 p 이하로 만드는데 실패한 것이다/
	if (size() <= 2 && max() > p)
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

void heap::make_and_insert()
{
	vector<int> new_list;

	// 상위 3개의 온도를 가진 물질 추출
	new_list.push_back(max());
	removeMax();
	new_list.push_back(max());
	removeMax();
	new_list.push_back(max());
	removeMax();

	sort(new_list.begin(), new_list.end());
	int result = (new_list[0] + new_list[2]) / 2; // 새로운 물질 생성

	insert(result); // 새로운 물질 힙에 추가 
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

		// 원소 할당
		for (int i = 0; i < n; i++)
		{
			int data;
			cin >> data;
			h.insert(data);
		}

		// 힙 물질이 3개 이상이며, 힙의 물질의 온도가 p보다 큰것이 존재할때 동안 합성 과정 반복
		// (즉, 힙 물질이 2개 이하이며, 힙의 모든 물질의 온도가 p보다 작으면 합성 과정 종료)
		int count = 0;	
		while (h.size() >= 3 && h.max() > p)
		{
			h.make_and_insert();
			count++;
		}
		h.print(p, count);
	}
}