// minPQ 를 가정, 홀수가 우선순위가 더 높다

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 비교자 - 두 원소의 우선순위를 비교하는 ADT
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
	void insert(int e);
	int max();
	void removeMax();
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
int sortedSeqPQ::max() {
	if (empty())
		return -1;

	return seq.front(); 
}

// unsortedSeqPQ 와 달리 이미 시퀀스가 정렬되있는 상태이므로, 그냥 바로 최솟값을 삭제하면 끝이다.
void sortedSeqPQ::removeMax() {
	if (empty())
		return;

	seq.erase(seq.begin());
}

void sortedSeqPQ::print()
{
	if (empty())
	{
		cout << "empty" << endl;
		return;
	}

	vector<int> list;

	// 오름차순 출력
	for (int i = 0; i < seq.size(); i++)
	{
		if (seq[i] % 2 == 1)
			cout << seq[i] << ' ';
		else
			list.push_back(seq[i]);
	}
	for (int i = 0; i < list.size(); i++)
	{
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
