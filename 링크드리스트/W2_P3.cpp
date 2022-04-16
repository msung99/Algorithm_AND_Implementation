#include <iostream>
#include <string>
using namespace std;

struct node {
	node* next;
	int data;
};

class singlyLinkedlist {
private:
	int listSize;
	node* head;
	node* tail;
public:
	singlyLinkedlist();
	void print();
	void append(int data);
	void delection(int idx);
	void insert(int idx, int data);
	void sum();
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
		}
		else
		{
			cout << head->data << endl;
			head = head->next;
			listSize--;
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
		cout << curNode->data << endl;
		if (curNode == tail)
			tail = preNode;
		preNode->next = curNode->next;
		delete curNode;
		listSize--;
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
			print();
		}
		else
		{
			newNode->next = head;
			head = newNode;
			listSize++;
			print();
		}
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
		print();
	}
}

void singlyLinkedlist::sum()
{
	if (empty())
	{
		cout << 0 << endl;
		return;
	}

	int sum = 0;
	node* curNode = head;
	while (curNode != NULL)
	{
		sum += curNode->data;
		curNode = curNode->next;
	}
	cout << sum << endl;
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
		else if (command == "Delete")
		{
			int a;
			cin >> a;
			s.delection(a);
		}
		else if (command == "Print")
		{
			s.print();
		}
		else if (command == "Insert")
		{
			int a, b;
			cin >> a >> b;
			s.insert(a, b);
		}
		else if (command == "Sum")
		{
			s.sum();
		}
	}
}
