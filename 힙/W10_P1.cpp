#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 배열(벡터) 기반 최소힙 
class heap {
private:
	vector<int> arr; // 힙의 원소를 저장하는 시퀀스(벡터)
	void swap(int idx1, int idx2);
	void upHeap(int idx);  // 힙의 인덱스 idx에 저장된 원소에서 upHeap 을 수행
	void downHeap(int idx);  // 힙의 인덱스 idx에 저장된 원소에서 downHeap 을 수행
public:
	heap();
	int size();
	bool empty();
	void insert(int data);
	int min();
	void removeMin();
	void print();
};

heap::heap() {
	arr.push_back(0); // 0번 인덱스를 일단 0으로 초기화.
}

int heap::size() {
	return arr.size() - 1; // 0번 인덱스에 저장된 데이터는 무시해야 하므로, arr.size() 에서 1을 뺀 값을 리턴
}

bool heap::empty() {
	return (arr.size() == 1); // // 0번 인덱스에 저장된 데이터는 무시해야 하므로 사이즈가 1일때 빈 것임 
}

// 비어있는 인덱스 0을 활용해 두 인덱스 idx1, idx2에 위치한 원소를 교체
void heap::swap(int idx1, int idx2) {
	arr[0] = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = arr[0];
}

void heap::insert(int data) {
	arr.push_back(data); // 과정1) 구조 조건 : O(1)
	upHeap(size()); // 과정2) 순서 조건 : O(log n)
}

void heap::upHeap(int idx) {
	if (idx == 1)  // 루트 노드에 도달할 경우 upHeap 종료 
		return;

	// 자신의 직계 부모보다 자신의 key 값이 더 클때까지 계속 upHeap 을 수행
	// upHeap 을 마치고 나면, 적절한 위치를 찾아갔을 것임.
	int parent = idx / 2;
	if (arr[parent] > arr[idx]) {
		swap(parent, idx);
		upHeap(parent);
	}
}

// 루트 노드 데이터( = 인덱스 1에 저장된 데이터 ) 를 리턴
int heap::min()
{
	if (empty())
		return -1;

	return arr[1]; // 루트 노드 데이터 리턴
}

// 최솟값 삭제 
void heap::removeMin()
{
	if (empty())
	{
		cout << -1 << endl;
		return;
	}
	// 단계1) 구조적 조건 : O(1)
	swap(1, size()); // 과정1) 맨 마지막 데이터를 루트 노드에 덮어씌우기
	cout << arr.back() << endl;
	arr.pop_back(); // 과정2) 맨 마지막 데이터 삭제


	// 단계2) 순서 조건 : 2 x O(log n)
	downHeap(1); // 다운힙을 수행해서, 최신화된 루트 노드 데이터가 적절한 위치를 찾아가도록 하기
}

void heap::downHeap(int idx) {
	int left = 2 * idx;
	int right = 2 * idx + 1;

	int child; // 왼쪽, 오른쪽 자식 중 현재 자신과 swap 을 진행할 자식의 인덱스 

	// 두 자식 모두 존재하지 않을 경우 downHeap 종료
	if (left > size()) {
		return;
	}

	// 왼쪽 자식만 존재하는 경우
	else if (left == size()) {
		child = left;
	}

	// 왼쪽, 오른쪽 자식 모두 존재하는 경우
	// 두 자식중 더 작은 자식을 찾아낸다.
	else {
		if (arr[left] <= arr[right]) // child 대입
			child = left;
		else
			child = right;
	}

	// heap-order 를 만족하지 않는 경우. 즉, downHeap을 진행해야 하는 경우 
	// 찾아낸 더 작은 자식과 현재 자신을 swap 을 할지를 판단하고 swap 을 진행

	if (arr[child] < arr[idx]) {  // 자신이 자식 key 값 보다 더 작아서 downHeap 을 진행해야 하는 경우
		swap(child, idx); // 자식의 값과 swap
		downHeap(child); // 또 다운힙 수행
	}
}

void heap::print()
{
	if (empty())
	{
		cout << -1 << endl;
		return;
	}

	// 인덱스 0은 빈 인덱스 이므로, 인덱스 1부터 출력
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
			h.removeMin();
		}
		else if (a == "top")
		{
			cout << h.min() << endl;
		}
		else if (a == "print")
		{
			h.print();
		}
	}
}