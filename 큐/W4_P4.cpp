#include <iostream>
#include <string>
using namespace std;

struct node {
	node* next;
	int data;
};

class Queue {
private:
	node* frontNode;
	node* rearNode;
	int listSize;
public:
	Queue();
	void enqueue(int data);
	void dequeue();
	int front();
	bool empty();
};

Queue::Queue()
{
	frontNode = NULL;
	rearNode = NULL;
	listSize = 0;
}

bool Queue::empty()
{
	return (listSize == 0);
}


int Queue::front()
{
	if (empty())
		return -1;

	return frontNode->data;
}

void Queue::enqueue(int data)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	if (empty())
	{
		frontNode = rearNode = newNode;
		listSize++;
	}
	else
	{
		rearNode->next = newNode;
		rearNode = newNode;
		listSize++;
	}
}

void Queue::dequeue()
{
	if (empty())
		return;
	if (listSize == 1)
	{
		frontNode = rearNode = NULL;
		listSize--;
	}
	else
	{
		node* tmp = frontNode;
		frontNode = frontNode->next;
		listSize--;
		delete tmp;
	}
}

void play(Queue q1, Queue q2, int round)
{
	for (int i = 0; i < round; i++)
	{
		int data;
		cin >> data;
		q1.enqueue(data);
	}
	for (int i = 0; i < round; i++)
	{
		int data;
		cin >> data;
		q2.enqueue(data);
	}

	int p1_score = 0, p2_score = 0, last_score = 0, winner = 0;
	for (int i = 0; i < round; i++)
	{
		int player1 = q1.front();
		int player2 = q2.front();
		
		// W2_P2 문제와 다른점 
		if (winner == 1) // 플레이어1이 이겼다면 플레이어 2에게 채력을 추가해줌
			player2 += last_score;
		else if (winner == 2) // 플레이어2가 이겼다면 플레이어 1에게 채력을 추가해줌
			player1 += last_score;

		if (player1 > player2)
		{
			winner = 1;
			last_score = player1 - player2;
			p1_score++;
		}
		else if (player1 < player2)
		{
			winner = 2;
			last_score = player2 - player1;
			p2_score++;
		}
		else if (player1 == player2)
		{
			winner = 0;
			last_score = 0;
		}

		if (winner == 1)
		{
			cout << "Round" << i + 1 << " P1 " << last_score << endl;
		}
		else if (winner == 2)
		{
			cout << "Round" << i + 1 << " P2 " << last_score << endl;
		}
		else if (winner == 0)
		{
			cout << "Round" << i + 1 << " Draw" << endl;
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

int main(void)
{
	int testCase;
	cin >> testCase;

	Queue q1;
	Queue q2;

	while (testCase--)
	{
		int round;
		cin >> round;
		play(q1, q2, round);
	}
}
