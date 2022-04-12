#include <iostream>
#include <string>
using namespace std;

struct node {
	node* next;
	node* prev;
	int data;
};

class Doublylinkedlist {
private:
	node* head;
	node* tail;
	int listSize;
public:
	Doublylinkedlist();
	bool empty();
	void print();
	void append(int data);
	void delection(int idx);
	void insertion(int idx, int data);
	void sum();
	void print_reverse();
	void max();
}; 

Doublylinkedlist::Doublylinkedlist()
{
	head = NULL;
	tail = NULL;
	listSize = 0;
}

bool Doublylinkedlist::empty()
{
	return (listSize == 0);
}

void Doublylinkedlist::print()
{
	if (empty())
	{
		cout << "Empty" << endl;
		return;
	}
	node* curNode = head;
	while (curNode != NULL)
	{
		cout << curNode->data << ' ';
		curNode = curNode->next;
	}
	cout << endl;
}

void Doublylinkedlist::append(int data)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	if (empty())
	{
		head = newNode;
		tail = newNode;
		listSize++;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		listSize++;
	}
	print();
}

void Doublylinkedlist::delection(int idx)
{
	if (idx < 0 || idx >= listSize || empty())
	{
		cout << -1 << endl;
		return;
	}
	if (idx == 0)
	{
		if (listSize == 1)
		{
			head = NULL;
			tail = NULL;
			listSize--;
		}
		else
		{
			head = head->next;
			listSize--;
		}
	}
	else if (idx == listSize - 1)
	{
		node* tmp = tail;
		tail = tail->prev;
		tail->next = NULL;
		listSize--;
		delete tmp;
	}
	else
	{
		node* curNode = head;
		node* preNode = head;
		for (int i = 0; i < idx; i++)
		{
			preNode = curNode;
			curNode = curNode->next;
		}
		curNode->next->prev = preNode;
		preNode->next = curNode->next;
		listSize--;
		delete curNode;
	}
}

void Doublylinkedlist::print_reverse()
{
	if (empty())
	{
		cout << "empty" << endl;
		return;
	}
	node* curNode = tail;
	while (true)
	{
		if (curNode == head)
		{
			cout << curNode->data << endl;
			break;
		}
		else
		{
			cout << curNode->data << ' ';
			curNode = curNode->prev;
		}
	}
}

void Doublylinkedlist::max()
{
	int max = 0;
	node* curNode = head;
	while (curNode != NULL)
	{
		if (max < curNode->data)
			max = curNode->data;
		curNode = curNode->next;
	}
	cout << max << endl;
}

int main(void)
{
	Doublylinkedlist d;
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		string command;
		cin >> command;
		if (command == "delete")
		{
			int idx;
			cin >> idx;
			d.delection(idx);
		}
		else if (command == "append")
		{
			int data;
			cin >> data;
			d.append(data);
		}
		else if (command == "print_reverse")
		{
			d.print_reverse();
		}
		else if (command == "max")
		{
			d.max();
		}
		else if (command == "print")
		{
			d.print();
		}
	}
}