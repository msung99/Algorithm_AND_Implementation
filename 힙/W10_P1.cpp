#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 배열기반 힙. min Heap 을 가정.
class heap {
private:
	vector<int> arr;
public:
	heap();
	void swap(int idx1, int idx2);
	void upHeap(int idx);  // 힙의 인덱스 idx 에 저장된 원소에서 upHeap 을 수행
	void downHeap(int idx);  // 힙의 인덱스 idx 에 저장된 원소에서 downHeap 을 수행

	int size();
	bool empty();
	void insert(int data);
	int min();
	void removeMin();
	void print();
};

heap::heap() {
	arr.push_back(0);   //  인덱스 0에는 데이터 저장안하므로 0으로 초기화.
	                    // 몰론 나중에 두 인덱스의 값을 swap 할때 0번 인덱스가 활용되긴 함
}

int heap::size() {
	return arr.size() - 1;  // 0번 인덱스 제외하고 사이즈 계산하기 위해 1을 뺌
}

bool heap::empty() {
	return (arr.size() == 1);   // 힙이 빈 상태라면, 0번 인덱스에만 데이터가 저장되어있는 상태이므로 사이즈가 1이다.
}

// 0번 인덱스를 활용해서 두 인덱스에 저장된 데이터를 swap
void heap::swap(int idx1, int idx2) {
	arr[0] = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = arr[0];
}

// 삽입 연산
// 1단계 : 힙의 맨 끝에다 (즉 배열의 맨 끝 원소의 다음 셀에다) 데이터를 삽입    => O(1)
// 2단계 : 삽입된 데이터가 힙 순서조건을 만족하지 않을 수 있으므로, upHeap 을 수행 => O(log n)
void heap::insert(int data) {
	arr.push_back(data);  // 1단계
	upHeap(size());  //  2단계 
}

void heap::upHeap(int idx) {
	if (idx == 1) // 루트에 도달할 경우 종료
		return;

	int parent = idx / 2;  // 현재 노드의 부모노드의 인덱스

	if (arr[parent] > arr[idx]) {   // 순서 조건을 만족하지 않는 경우. 즉, 부모 노드의 값이 더 작은 경우
		swap(parent, idx);  // 서로 위치를 바꾸고 
		upHeap(parent);   // 또 upHeap 을 수행
	}
}

int heap::min() {
	if (empty())
		return -1;

	return arr[1]; // 최솟값은 루트 노드에 위치
}

// 삭제 연산
// 1단계 : 힙의 가장 마지막 노드의 데이터 ( = 배열의 맨 끝에 저장된 데이터) 를 루트 노드에 덮어씌우기 (여기서는 보니까 덮어씌우는게 아니라 교채함)
// 2단계 : 기존의 가장 마지막 노드를 삭제하고, 새롭게 루트 노드가 된 노드가 힙 순서조건을 만족하지 않을수도 있으므로 다운힙을 수행
void heap::removeMin() {
	if (empty())
	{
		cout << -1 << endl;
		return;
	}

	swap(1, size()); // 1단계

	// 2단계
	cout << arr.back() << endl;
	arr.pop_back(); // 가장 마지막 원소 제거
	downHeap(1); // 다운힙 수행 => 1을 인자로 주는 이유는, 인덱스 1에 있는 노드인 루트에서부터 다운힙을 수행하기 위함
}


// 다운힙 과정
// 1. 두 자식 중 더 작은 자식이 누군지를 비교하기
// 2. 찾아낸 더 작은 자식과 자신을 비교해서, 자신이 더 작다면(힙 순서조건을 아직 만족하지 않는다면) 내려가기 (swap 하기)
void heap::downHeap(int idx) {
	int left = 2 * idx;  // left, right => 왼쪽과 오른쪽 자식의 인덱스
	int right = 2 * idx + 1;
	int child; // child 에는 두 자식 중에서 자신이 내려갈 자식이 (자신과 swap 될 자식) 저장된다.

	if (left > size())  // 자식이 아예 존재하지 않는 경우
		return;

	else if (left == size()) {   // 왼쪽 자식만 존재하는 경우
		child = left;    // 더 작은 자식을 왼쪽 자식으로 설정
	}
	
	else {   // 두 자식 모두 존재하는 경우
		// 더 작은 자식을 찾아내고 child 로 설정 
		if (arr[left] <= arr[right])
			child = left;
		else
			child = right;
	}
	
	// 과정2. 앞서 찾아낸 더 작은 자식과 자신을 비교해서 내려말지 말지를 판단한다.

	// 힙 순서조건을 만족하지 않는 경우 ( = 자신이 찾아낸 더 작은 자식 child 보다 더 작은 경우) 내려간다. 
	if (arr[child] < arr[idx]) {
		swap(child, idx);
		downHeap(child);  // 또 다운힙 수행 
	}
}

void heap::print()
{
	if (empty())
	{
		cout << "-1" << endl;
		return;
	}

	// 인덱스 0은 빈 인덱스이므로, 인덱스 1부터 출력
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
