// minPQ 를 가정, 홀수가 우선순위가 더 높다

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 비교자 - 두 원소의 우선순위를 비교하는 ADT
// compare(p ,q) : p가 q보다 우선순위가 높은지를 판단.
struct compare {
	bool operator()(const int& p, const int& q) const {
		return p > q;
	}
};

// maxPQ 를 구현 비정렬 시퀀스 벡터로 구현
class unsortedSeqPQ {
private:
	vector<int> seq;
public:
	int size();
	bool empty();
	void insert(int e);
	int max();
	void removeMax();
	void print();
};

int unsortedSeqPQ::size() {
	return seq.size();
}

bool unsortedSeqPQ::empty() {
	return (seq.size() == 0);
}

// 우선순위 큐에 원소 e를 삽입
// 정렬같은거 안하고, 그냥 시퀀스 맨 뒤에 원소 삽입
void unsortedSeqPQ::insert(int data) {
	seq.push_back(data);
}

// 비교자(정렬기준) C에 따라서 최솟값을 탐색
// 정렬되지 않은 시퀀스에서 맨앞에서부터 맨 끝까지 싹다 탐색하면서 최댓값 찾아내기
int unsortedSeqPQ::max() {
	if (empty())
		return -1;

	compare C;
	int max_value = seq[0];
	for (int i = 0; i < seq.size(); i++) {
		if (C(seq[i], max_value))
			max_value = seq[i];
	}
	return max_value;
}

// 정렬되지 않은 시퀀스에서 맨앞에서부터 맨 끝까지 싹다 탐색하면서
// 최댓값 찾아내고 삭제
void unsortedSeqPQ::removeMax() {
	if (empty())
		return;

	compare C;
	int maxIdx = 0;
	for (int i = 0; i < seq.size(); i++) {
		if (C(seq[i], seq[maxIdx]))
			maxIdx = i;
	}
	seq.erase(seq.begin() + maxIdx);
}


int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		// 선택정렬(selection sort)를 위해 PQ를 비정렬 시퀀스 벡터로 구현
		unsortedSeqPQ q;
		int n;
		cin >> n;

		// 1) 시퀀스 내용을 정렬하지 않고 그대로 PQ 배열에 카피후,
		while (n--) 
		{
			int data;
			cin >> data;
			q.insert(data);
		}

		// 2) 최댓값을 일일이 맨 앞에서부터 비교하면서 찾아내고, 찾아낸 최댓값을 PQ 에서 출력과 동시에 삭제
		int q_size = q.size(); 
		for (int i = 0; i < q_size; i++) 
		{
			cout << q.max() << ' '; // 최댓값 출력하고
			q.removeMax(); // 최댓값 삭제
		}
		cout << endl;
	}
}
