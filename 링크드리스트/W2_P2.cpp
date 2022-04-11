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
	bool empty();
	void print();
	void append(int data);
	void delection(int idx);
	void insertion(int idx, int data);
	void sum();
	void print_reverse();
	void max();
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


void doublyLinkedlist::append(int data)
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
}

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

void doublyLinkedlist::delection(int idx)
{
	if (idx < 0 || idx >= listSize || empty())
	{
		cout << -1 << endl;
		return;
	}

	node* curNode = head;
	if (idx == 0) // head »èÁ¦ => O(1)
	{
		if (listSize == 1)
		{
			head = tail = NULL;
		}
		else
		{
			head = head->next;
		}
	}

	
	else if (idx == listSize-1) // tail »èÁ¦ => O(1)
	{
		node* tmp = tail;
		tail = tmp->prev;
		tail->next = NULL;
		delete tmp;
		listSize--;
	}
	
	else // Áß°£ ³ëµå »èÁ¦ => O(n)
	{
		node* preNode = head;
		for (int i = 0; i < idx; i++)
		{
			preNode = curNode;
			curNode = curNode->next;
		}
		preNode->next = curNode->next;
		curNode->next->prev = preNode;
		delete curNode;
		listSize--;
	}
}

void doublyLinkedlist::sum()
{
	if (empty())
	{
		cout << 0 << endl;
		return;
	}
	int result = 0;
	node* curNode = head;
	while (curNode != NULL)
	{
		result += curNode->data;
		curNode = curNode->next;
	}
	cout << result << endl;
}

void doublyLinkedlist::print_reverse()
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
			return;
		}
		cout << curNode->data << ' ';
		curNode = curNode->prev;
	}
}

void doublyLinkedlist::max()
{
	int max = -99999;
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
	doublyLinkedlist d;
	int testCase;
	cin >> testCase;
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
			int data, idx;
			cin >> idx >> data;
			d.insertion(idx, data);
		}
		else if (command == "print")
		{
			d.print();
		}
		else if (command == "sum")
		{
			d.sum();
		}
		else if (command == "print_reverse")
		{
			d.print_reverse();
		}
		else if (command == "max")
		{
			d.max();
		}
	}
}
