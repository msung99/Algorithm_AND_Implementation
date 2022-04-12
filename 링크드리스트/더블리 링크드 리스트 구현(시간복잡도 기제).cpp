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
	int listSize;
	node* head;
	node* tail;
public:
	Doublylinkedlist();
	bool empty();
	void append(int data);
	void insertion(int idx, int data);
	void delection(int idx);
	void print();
};

Doublylinkedlist::Doublylinkedlist()
{
	listSize = 0;
	head = NULL;
	tail = NULL;
}

bool Doublylinkedlist::empty()
{
	return (listSize == 0);
}

void Doublylinkedlist::append(int data)
{
	node* newNode = new node;
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->data = data;
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
}


void Doublylinkedlist::insertion(int idx, int data)
{
	if (idx < 0 || idx > listSize)
		return;

	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (idx == 0)
	{
		if (listSize == 0)
		{
			append(data);
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
			listSize++;
		}
	}
	else if (idx == listSize)
	{
		append(data);
	}
	else
	{
		node* curNode = head;
		for (int i = 0; i < idx - 1; i++)
		{
			curNode = curNode->next;
		}
		curNode->next->prev = newNode;
		newNode->next = curNode->next;
		curNode->next = newNode;
		newNode->prev = curNode;
		listSize++;
	}
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
	else if(idx == listSize-1)
	{
		node* tmp = tail;
		tail = tmp->prev;
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
		preNode->next = curNode->next;
		curNode->next->prev = preNode;
		listSize--;
		delete curNode;
	}
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

int main(void)
{
	int testCase;
	cin >> testCase;

	Doublylinkedlist d;

	while (testCase--)
	{
		string command;
		cin >> command;
		if (command == "append")
		{
			int data;
			cin >> data;
			d.append(data);
		}
		else if (command == "delete")
		{
			int idx;
			cin >> idx;
			d.delection(idx);
		}
		else if (command == "insert")
		{
			int idx, data;
			cin >> idx >> data;
			d.insertion(idx, data);
		}
		else if (command == "print")
		{
			d.print();
		}
	}
}
