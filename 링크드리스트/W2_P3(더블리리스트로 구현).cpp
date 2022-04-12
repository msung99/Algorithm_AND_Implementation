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


void Doublylinkedlist::append(int data)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
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

void Doublylinkedlist::insertion(int idx, int data)
{
	if (idx < 0 || idx > listSize)
	{
		cout << "Index Error" << endl;
		return;
	}
	node* newNode = new node;
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;

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
			cout << head->data << endl;
			head = NULL;
			tail = NULL;
			listSize--;
		}
		else
		{
			cout << head->data << endl;
			head = head->next;
			listSize--;
		}
	}
	else if (idx == listSize-1)
	{
		cout << tail->data << endl;
		node* tmp = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete tmp;
		listSize--;
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
		cout << curNode->data << endl;
		listSize--;
		delete curNode;
	}
}

void Doublylinkedlist::print()
{
	if (empty())
	{
		cout << "EMPTY" << endl;
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

void Doublylinkedlist::sum()
{
	int sum = 0;

	if (empty())
	{
		cout << "0" << endl;
		return;
	}
	node* curNode = head;
	while (curNode != NULL)
	{
		sum +=  curNode->data;
		curNode = curNode->next;
	}
	cout << sum << endl;
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
		if (command == "print")
		{
			d.print();
		}
		else if (command == "append")
		{
			int idx;
			cin >> idx;
			d.append(idx);
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
		else if (command == "sum")
		{
			d.sum();
		}
	}
}