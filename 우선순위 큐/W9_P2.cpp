#include <iostream>
#include <vector>
using namespace std;

// 비교자
struct compare {
	// 두 정수 e1, e2를 비교해서
	// e1 < e2 일 경우 True를, 아닐 경우 False를 리턴
	bool operator()(const int& e1, const int& e2) const {
		return e1 < e2;
	}
};

class unsortedSeqPQ {
private:
	vector<int> seq; // 정렬되지 않은 시퀀스를 저장하는 벡터
public:
	int size();
	bool empty();
	void insert(int e);
	int min();
	void removeMin();
};

int unsortedSeqPQ::size()
{
	return seq.size();
}

bool unsortedSeqPQ::empty()
{
	return (seq.size() == 0);
}

// 우선순위 큐에 원소 e를 삽입하는 함수
void unsortedSeqPQ::insert(int e)
{
	seq.push_back(e); // 시퀀스의 가장 마지막 위치에 원소를 삽입
}

// 우선순위가 가장 높은 ( = 값이 가장 작은) 원소를 리턴하는 함수
int unsortedSeqPQ::min()
{
	if (empty())
		return -1;

	compare C; // 비교자 변수 선언
	int minVal = seq[0]; 

	// 시퀀스를 순차적으로 탐색하며
	for (int i = 0; i < seq.size(); i++)
	{
		// 가장 우선순위가 높은 원소를 minVal에 저장
		if (C(seq[i], minVal))
		{
			minVal = seq[i];
		}
	}
}

// 우선순위가 가장 높은(= 가장 값이 작은) 원소를 삭제하는 함수
void unsortedSeqPQ::removeMin()
{
	if (empty())
		return;

	compare C; // 비교자 변수 선언
	int minIdx = 0;

	// 시퀀스를 순차적으로 탐색하며
	// 가장 우선순위가 높은 원소의 인덱스를 minIdx 에 저장
	for (int i = 0; i < seq.size(); i++)
	{
		if (C(seq[i], seq[minIdx]))
			minIdx = i;
	}
	seq.erase(seq.begin() + minIdx);  // 시퀀스에 가장 우선순위가 높은 원소 minIdx 를 삭제
}

//////////////////////////////////////////////////////////////////////

class sortedSeqPQ {
private:
	vector<int> seq; // 내림차순으로 정렬된 시퀀스를 저장하는 벡터
public:
	int size();
	bool empty();
	void insert(int e);
	int min();
	int max();
	void removeMin();
	void removeMax();
	void print();
};


int sortedSeqPQ::size()
{
	return seq.size();
}

bool sortedSeqPQ::empty()
{
	return (seq.size() == 0);
}

// 우선순위 큐에 원소 e를 삽입하는 함수
void sortedSeqPQ::insert(int e)
{
	compare C;
	int idx = 0;

	// 시퀀스를 순차적으로 탐색하며
	// 삽입할 원소보다 우선순위가 높은 원소가 처음 등장하는 위치 탐색
	for (idx = 0; idx < seq.size(); idx++) {
		if (C(seq[idx], e))
			break;
	}

	seq.insert(seq.begin() + idx, e); // 찾은 위치의 앞에 새로운 원소 e 삽입
}

// 우선순위가 가장 높은 원소(= 최솟값)를 리턴하는 함수
int sortedSeqPQ::min()
{
	if (empty())
		return -1;

	return seq.back(); // 시퀀스의 가장 마지막 원소를 리턴
}

/*
void sortedSeqPQ::min()
{
	if (empty())
	{
		cout << "empty" << endl;
		return;
	}
	cout << seq.back() << endl;
}
*/

// 우선순위가 가장 낮은 원소( = 최댓값) 을 리턴
int sortedSeqPQ::max()
{
	if (empty())
		return -1;

	return seq.front(); 
}

/*
void sortedSeqPQ::max()
{
	if (empty())
	{
		cout << "empty" << endl;
		return;
	}
	cout << seq.front() << endl;
}
*/

// 우선순위가 가장 높은 원소를 삭제하는 함수
void sortedSeqPQ::removeMin()
{
	if (empty())
	{
		cout << "empty" << endl;
		return;
	}
	seq.pop_back(); // 시퀀스의 가장 마지막 원소를 삭제
}

// 최댓값 삭제 
void sortedSeqPQ::removeMax()
{
	if (empty())
	{
		cout << "empty" << endl;
		return;
	}
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
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		sortedSeqPQ s;
		int count;
		cin >> count;
		for (int i = 0; i < count; i++)
		{
			int data;
			cin >> data;
			s.insert(data);
		}
		s.print();
	}
}
	/*
	while (testCase--)
	{
		string a;
		cin >> a;
		if (a == "size")
		{
			cout << s.size() << endl;
		} 

		else if (a == "empty")
		{
			if (s.empty())
				cout << "empty" << endl;
			else
				cout << "Not empty" << endl;
		}

		else if (a == "insert")
		{
			int b;
			cin >> b;
			s.insert(b);
		}

		else if (a == "min")
		{
			cout << s.min() << endl;
		}

		else if (a == "removeMin")
		{
			s.removeMin();
		}
		else if (a == "removeMax")
		{
			s.removeMax();
		}

		else if (a == "print")
		{
			s.print();
		}
		else if (a == "max")
		{
			cout << s.max() << endl;
		}
	}
	*/