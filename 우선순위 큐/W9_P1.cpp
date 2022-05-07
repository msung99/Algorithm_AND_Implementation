#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 비교자 - 두 원소의 우선순위를 비교하는 ADT
// compare(p ,q) : p가 q보다 우선순위가 높은지를 판단.
// ex) compare(10,3) : 10 < 3 ? => false (10이 3보다 우선순위가 낮으므로 false를 리턴)
struct compare {
	bool operator()(const int& p, const int& q) const {
		return p > q;  // 만일 maxPQ 가 아닌 minPQ 의 비교자를 구현한다면, 
	}                  // 우선순위가 최댓값 아닌 최솟값이므로 "return p < q" 로 수정해야 한다. (여기서는 minPQ를 가정)
};


class sortedSeqPQ {
private:
	vector<int> seq; // 내림차순으로 정렬된 시퀀스를 저장하는 벡터
public:
	int size();
	bool empty();
	void insert(int e);
	int min();
	void removeMin();
	void print();
};

int sortedSeqPQ::size() {
	return seq.size();
}

bool sortedSeqPQ::empty() {
	return (seq.size() == 0);
}

// unsortedSeqPq 과 달리, 시퀀스 벡터에 원소를 삽입시 그냥 삽입하지 않고 삽입될 적절한 위치를 찾아가서 삽입된다.
void sortedSeqPQ::insert(int data) {
	compare C;
	int idx = 0;

	// data 원소가 삽입될 적절한 위치를 탐색
	for (idx = 0; idx < seq.size(); idx++) {
		if (C(seq[idx], data))  // 삽입할 원소보다 우선순위가 높은(= key값이 더 작은) 원소가 처음 등장하는 위치를 탐색 
			break;
	}
	seq.insert(seq.begin() + idx, data);  // 찾은 위치에 새로운 데이터 값 삽입
}

// unsortedSeqPQ 와 달리 이미 시퀀스가 정렬되있는 상태이므로, 그냥 바로 최솟값 리턴해주면 된다.
int sortedSeqPQ::min() {
	if (empty())
		return -1;

	return seq.back(); // 시퀀스 맨 뒤에 저장되있는 최솟값을 리턴
}

// unsortedSeqPQ 와 달리 이미 시퀀스가 정렬되있는 상태이므로, 그냥 바로 최솟값을 삭제하면 끝이다.
void sortedSeqPQ::removeMin() {
	if (empty())
		return;

	seq.pop_back(); // 시퀀스 맨 뒤에 저장되있는 최솟값을 삭제
}

void sortedSeqPQ::print() {
	for (int i = 0; i < seq.size(); i++) {
		cout << seq[i] << ' ';
	}
	cout << endl;
}

int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		// 삽입 정렬 (Insertion sort) 수행 => sorted 시퀀스로 구현
		sortedSeqPQ q;
		int n;
		cin >> n;
		while (n--)  // PQ 시퀀스에 원소를 넣을때마다 계속 정렬된 상태 유지
		{
			int data;
			cin >> data;
			q.insert(data);
		}
		q.print();
	}
}