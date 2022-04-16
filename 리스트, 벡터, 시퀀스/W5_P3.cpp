#include <iostream>
#include <string>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class nodeList {
private:
	node* header;
	node* trailer;
	int listSize;
public:
	nodeList();
	node* begin();
	node* end();
	void insert(node* pos, int data);
	node* erase(node* pos);
	node* nextP(node* pos);
	node* prevP(node* pos);
	void print();
	void upper(int data);
	bool empty();
};

nodeList::nodeList()
{
	header = new node;
	trailer = new node;

	header->next = trailer;
	header->prev = NULL;
	trailer->prev = header;
	trailer->next = NULL;

	listSize = 0;
}

node* nodeList::begin()
{
	return header->next;
}

node* nodeList::end()
{
	return trailer;
}

bool nodeList::empty()
{
	return (listSize == 0);
}

void nodeList::insert(node* pos, int data)
{
	node* newNode = new node;
	newNode->data = data;

	pos->prev->next = newNode;
	newNode->prev = pos->prev;
	pos->prev = newNode;
	newNode->next = pos;

	listSize++;
}

node* nodeList::erase(node* pos)
{
	if (empty())
	{
		cout << "Empty" << endl;
		return pos;
	}

	if (pos == trailer)
		return pos;

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	delete pos;
	listSize--;

	return begin();
}

node* nodeList::nextP(node* pos)
{
	if (pos == trailer)
		return pos;

	return pos->next;
}

node* nodeList::prevP(node* pos)
{
	if (pos == header->next)
		return pos;

	return pos->prev;
}

void nodeList::print()
{
	if (empty())
	{
		cout << " Empty" << endl;
		return;
	}

	node* curNode = begin();
	while (curNode != trailer)
	{
		cout << curNode->data << ' ';
		curNode = curNode->next;
	}
	cout << endl;
}

void nodeList::upper(int data)
{
	int index = 0;
	int check = 0;
	node* curNode = begin();
	while (curNode != trailer)
	{
		if (curNode->data > data)
		{
			cout << index << ' ';
			check = 1;
		}
		index++;
		curNode = curNode->next;
	}

	if (check == 0)
		cout << -1;

	cout << endl;
}

int main(void)
{
	nodeList list;
	node* p = list.begin();
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		string a;
		cin >> a;
		if (a == "begin")
		{
			p = list.begin();
		}
		else if (a == "end")
		{
			p = list.end();
		}
		else if (a == "insert")
		{
			int data;
			cin >> data;
			list.insert(p,data);
		}
		else if (a == "erase")
		{
			p = list.erase(p);
		}
		else if (a == "nextP")
		{
			p = list.nextP(p);
		}
		else if (a == "prevP")
		{
			p = list.prevP(p);
		}
		else if (a == "print")
		{
			list.print();
		}
		else if (a == "upper")
		{
			int data;
			cin >> data;
			list.upper(data);
		}
	}
}