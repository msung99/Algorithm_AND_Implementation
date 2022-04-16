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
	node* head;
	node* tail;
	int listSize;
public:
	doublyLinkedlist();
	void print();
	void append(int data);
	void delection(int idx);
	void print_reverse();
	void update(int data1, int data2);
	bool empty();
};

/*
void doublyLinkedlist::insertion(int idx, int data)
{
	if (idx < 0 || idx > listSize)
		return;

	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (idx == 0)
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		listSize++;
	}
	else if (idx == listSize)
	{
		append(data);
		listSize++;
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

*/

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
	newNode->prev = NULL;
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
		newNode->prev = tail;
		tail = newNode;
		listSize++;
		print();
	}
}

void doublyLinkedlist::delection(int idx)
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

void doublyLinkedlist::update(int x, int y)
{
	if (empty())
	{
		cout << "empty" << endl;
		return;
	}

	int check = 0;
	node* curNode = head;
	while (curNode != NULL)
	{
		if (curNode->data == x)
		{
			curNode->data = y;
			check = 1;
		}
		curNode = curNode->next;
	}
	if (check == 0)
	{
		cout << "Not found" << endl;
		return;
	}
	print();
}

int main(void)
{
	int testCase;
	cin >> testCase;
	doublyLinkedlist d;
	while (testCase--)
	{
		string command;
		cin >> command;;
		if (command == "Append")
		{
			int a;
			cin >> a;
			d.append(a);
		}
		else if (command == "Delete")
		{
			int a;
			cin >> a;
			d.delection(a);
		}
		else if (command == "Print_reverse")
		{
			d.print_reverse();
		}
		else if (command == "Print")
		{
			d.print();
		}
		else if (command == "Update")
		{
			int x, y;
			cin >> x >> y;
			d.update(x, y);
		}
	}
}
