#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 배열에서 우선순위가 가장 높은 원소는 맨 뒤에 위치해있다. => minPQ 인 경우 : 최솟값이 맨뒤에 위치, maxPQ인 경우 : 최댓값이 맨뒤에 위치
// max PQ 를 가정.  문제의 출력예시 보면, 오름차순으로 정렬되어 있다. 즉, 우선순위가 높은 갚이 배열의 뒤쪽에 위치해 있는다.

struct compare {
	bool operator()(const int& p, const int& q) const {
		return p > q; // p 가 우선순위 가 더 높은 경우, 즉 p 의 값이 더 큰 경우에 true를 리턴
	}
};


// 참고로 insert, print 함수만 구현해도 된다. (removeMax, max 는 구현할 필요x)
class sortedSeqPQ {
private:
	vector<int> seq;
public:
	int size();
	bool empty();
	void insert(int e);
	int max();
	void removeMax(); // 우선순위가 가장 높은 값(= 최댓값) 을 삭제. 이때 최댓값은 배열의 끝에 위치해 있음.
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

	// 삽입할 원소보다 우선순위가 더 높은 원소가 처음 등장하는 위치 탐색
	for (idx = 0; idx < seq.size(); idx++) {
		if (C(seq[idx], data)) // 삽입될 적절한 위치를 찾은 경우
			break;
	}
	seq.insert(seq.begin() + idx, data);
}

int sortedSeqPQ::max() {
	if (empty())
		return -1;

	return seq.back(); // 우선순위가 가장 높은 원소인 최댓값은 배열의 맨 뒤에 위치해 있는다.
}

void sortedSeqPQ::removeMax() {
	if (empty())
		return;

	seq.pop_back();  // 우선순위가 가장 높은 원소인 최댓값은 배열의 맨 뒤에 위치해 있는다.
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
