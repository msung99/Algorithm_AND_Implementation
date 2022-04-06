#include <iostream>
#include <string>
using namespace std;

struct node {
	node* next;
	int data;
};

class listQueue {
private:
	node* frontNode;
	node* rearNode;
	int n;
public:
	listQueue();
	void enqueue(int data);
	void dequeue();
	void front();
	bool empty();
	int size();
};

listQueue::listQueue()
{
	frontNode = rearNode = NULL;
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

void listQueue::front()
{
	if (empty())
		return;
	cout << frontNode->data << endl;
}

void listQueue::enqueue(int data) // rear 에서 추가연산 진행
{
	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	if (empty()) // empty() 일때 enqueue 연산 따로 처리하는 점 주의!
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

void listQueue::dequeue()  // front에서 노드 삭제연산진행 => 스택과 마찬가지임
{
	if (empty())
	{
		cout << "EMPTY" << endl;
		return;
	}
	if (n == 1) // 삭제 연산에서 n == 1 일떄 따로 처리해야한다는 점 주의!
	{
		frontNode = NULL;
		rearNode = NULL;
		n--;
	}
	else
	{
		node* tmp = frontNode;
		frontNode = frontNode->next;
		n--;
		delete tmp;
	}
}



