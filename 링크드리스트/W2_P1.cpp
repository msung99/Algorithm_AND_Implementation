#include <iostream>
#include <string>
using namespace std;

struct node {
	int data;
	node* next;
};

class singlyLinkedlist {
private:
	node* head;
	node* tail;
	int listSize;
public:
	singlyLinkedlist();
	void print();
	void append(int data);
	void delection(int idx);
	void insert(int idx, int data);
	void min();
	bool empty();
};

singlyLinkedlist::singlyLinkedlist()
{
	head = NULL;
	tail = NULL;
	listSize = 0;
}

bool singlyLinkedlist::empty()
{
	return (listSize == 0);
}

void singlyLinkedlist::append(int data)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	if (empty())
	{
		head = tail = newNode;
		listSize++;
		print();
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
		listSize++;
		print();
	}
}

void singlyLinkedlist::insert(int idx, int data)
{
	if (idx < 0 || idx > listSize)
	{
		cout << "Index Error" << endl;
		return;
	}

	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;

	if (idx == 0)
	{
		if (listSize == 0)
		{
			head = tail = newNode;
			listSize++;
		}
		else
		{
			newNode->next = head;
			head = newNode;
			listSize++;
		}
	}
	else if (idx == listSize)
	{
		tail->next = newNode;
		tail = newNode;
		listSize++;
	}
	else
	{
		node* curNode = head;
		for (int i = 0; i < idx - 1; i++)
		{
			curNode = curNode->next;
		}
		newNode->next = curNode->next;
		curNode->next = newNode;
		listSize++;
	}
	
	print();
}

void singlyLinkedlist::delection(int idx)
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
			head = tail = NULL;
			listSize--;
			return;
		}
		else
		{
			cout << head->data << endl;
			head = head->next;
			listSize--;
			return;
		}
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
		if (curNode == tail)
		{
			tail = preNode;
			preNode->next = NULL;
		}
		cout << curNode->data << endl;
		delete curNode;
		listSize--;
	}
}

void singlyLinkedlist::min()
{
	if (empty())
	{
		cout << "empty" << endl;
		return;
	}
	int min = 999999;
	node* curNode = head;
	while (curNode != NULL)
	{
		if (min > curNode->data)
			min = curNode->data;

		curNode = curNode->next;
	}
	cout << min << endl;
}

void singlyLinkedlist::print()
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

int main(void)
{
	singlyLinkedlist s;
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		string command;
		cin >> command;
		if (command == "Append")
		{
			int a;
			cin >> a;
			s.append(a);
		}
		else if (command == "Insert")
		{
			int a, b;
			cin >> a >> b;
			s.insert(a, b);
		}
		else if (command == "Print")
		{
			s.print();
		}
		else if (command == "Delete")
		{
			int idx;
			cin >> idx;
			s.delection(idx);
		}
		else if (command == "Min")
		{
			s.min();
		}
	}
}