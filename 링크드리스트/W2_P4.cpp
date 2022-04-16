#include <iostream>
#include <string>
using namespace std;

struct node {
	node* next;
	node* prev;
	int data;
};

class doublyLinkedlist {
private:
	int listSize;
	node* head;
	node* tail;
public:
	doublyLinkedlist();
	void print();
	void append(int data);
	void delection(int idx);
	void print_reverse();
	void max();
	bool empty();
};

doublyLinkedlist::doublyLinkedlist()
{
	listSize = 0;
	head = NULL;
	tail = NULL;
}

bool doublyLinkedlist::empty()
{
	return (listSize == 0);
}

void doublyLinkedlist::print()
{
	if (empty())
	{
		cout << "empty" << endl;
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

void doublyLinkedlist::append(int data)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (empty())
	{
		head = tail = newNode;
		listSize++;
		print();
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		listSize++;
		print();
	}
}

void doublyLinkedlist::delection(int idx)
{
	if (empty() || idx < 0 || idx >= listSize)
	{
		cout << -1 << endl;
		return;
	}
	
	if (idx == 0)
	{
		if (listSize == 1)
		{
			cout << head->data << endl;
			head = tail = NULL;
			listSize--;
		}
		else
		{
			cout << head->data << endl;
			head = head->next;
			head->prev = NULL;
			listSize--;
		}
	}
	else if (idx == listSize - 1)
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
		cout << curNode->data << endl;
		curNode->next->prev = preNode;
		preNode->next = curNode->next;
		delete curNode;
		listSize--;
	}
}

void doublyLinkedlist::print_reverse()
{
	if (empty())
	{
		cout << "empty" << endl;
		return;
	}
	node* curNode = tail;
	while (curNode != NULL)
	{
		cout << curNode->data << ' ';
		curNode = curNode->prev;
	}
	cout << endl;
}

void doublyLinkedlist::max()
{
	if (empty())
	{
		cout << "empty" << endl;
		return;
	}
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
	int testCase;
	cin >> testCase;

	doublyLinkedlist d;

	while (testCase--)
	{
		string command;
		cin >> command;
		if (command == "Delete")
		{
			int a;
			cin >> a;
			d.delection(a);
		}
		else if (command == "Print")
		{
			d.print();
		}
		else if (command == "Print_reverse")
		{
			d.print_reverse();
		}
		else if (command == "Append")
		{
			int a;
			cin >> a;
			d.append(a);
		}
		else if (command == "Max")
		{
			d.max();
		}
	}
}
