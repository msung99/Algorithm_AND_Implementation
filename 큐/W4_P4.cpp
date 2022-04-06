#include <iostream>
#include <string>
using namespace std;

struct node {
	int data;
	node* next;
};

class Queue {
	int data;
	node* next;
};

class listQueue {
private:
	node* frontNode;
	node* rearNode;
	int n;
public:
	listQueue();
	bool empty();
	int size();
	int front();
	int rear();
	void enqueue(int data);
	void dequeue();
};

listQueue::listQueue()
{
	frontNode = NULL;
	rearNode = NULL;
	n = 0;
}

bool listQueue::empty()
{
	return (n == 0);
}

int listQueue::size()
{
	return n;
}

int listQueue::front()
{
	if (empty())
	{
		cout << "Empty" << endl;
	}
	else
	{
		return frontNode->data;
	}
}


void listQueue::enqueue(int data)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;

	if (empty())
	{
		frontNode = newNode;
		rearNode = newNode;
		n++;
	}
	else
	{
		rearNode->next = newNode;
		rearNode = newNode;
		n++;
	}
}

void listQueue::dequeue()
{
	if (empty())
		return;
	node* tmp = frontNode;
	frontNode = frontNode->next;
	delete tmp;
	n--;
}


// W4_P2 문제와 다른점 : W4_P2 문제는 이긴 사람에게 채력을 추가해줬지만, 이 문제는 진 사람에게 채력을 추가해주는 것이다.
// 이거밖에 차이가 없다.
void play(int testCase, listQueue q1, listQueue q2)
{
	for (int k = 0; k < testCase; k++)
	{
		int card;
		cin >> card;
		for (int i = 0; i < card; i++)
		{
			int data;
			cin >> data;
			q1.enqueue(data);
		}
		for (int i = 0; i < card; i++)
		{
			int data;
			cin >> data;
			q2.enqueue(data);
		}
		int last_score = 0, p1_score = 0, p2_score = 0, who_win = 0;
		for (int i = 0; i < card; i++)
		{
			int p1_card = q1.front();
			int p2_card = q2.front();

			if (who_win == 1) // 플레이어1이 이겼다면 플레이어 2에게 채력을 추가해줌
				p2_card += last_score;  
			else if (who_win == 2) // 플레이어2가 이겼다면 플레이어 1에게 채력을 추가해줌
				p1_card += last_score;

			if (p1_card > p2_card)
			{
				last_score = p1_card - p2_card;
				p1_score++;
				who_win = 1;
			}
			else if (p1_card < p2_card)
			{
				last_score = p2_card - p1_card;
				p2_score++;
				who_win = 2;
			}
			else if (p1_card == p2_card)
			{
				who_win = 0;
			}

			if (who_win == 1)
			{
				cout << "Round" << i + 1 << " " << "P1" << ' ' << last_score << endl;
			}
			else if (who_win == 2)
			{
				cout << "Round" << i + 1 << " " << "P2" << ' ' << last_score << endl;
			}

			q1.dequeue();
			q2.dequeue();
		}
		if (p1_score > p2_score)
			cout << "Winner P1" << endl;
		else if (p1_score < p2_score)
			cout << "Winner P2" << endl;
		else if (p1_score == p2_score)
			cout << "Draw" << endl;
	}
}

int main(void)
{
	listQueue q1;
	listQueue q2;
	int testCase;
	cin >> testCase;

	play(testCase, q1, q2);
}