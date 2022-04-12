#include <iostream>
#include <string>
using namespace std;

struct node {
	int data;
	node* prev;
	node* next;
};

class arrayList {
private:
	int listSize;
	node* header;
	node* trailer;
public:
	arrayList();
	bool empty();
	node* begin();
	node* end();
	void insert(node* pos, int data);
	node* erase(node* pos);
	void insertFront(int data);
	void insertBack(int data);
	void eraseFront();
	void eraseBack();
	node* nextP(node* pos);
	node* prevP(node* pos);
	void find(int data);
	void print();
	void find_max(int arr[]);
	void find_min(int arr[]);
};

arrayList::arrayList()
{
	header = new node;
	trailer = new node;

	header->next = trailer;
	header->prev = NULL;
	trailer->prev = header;
	trailer->next = NULL;

	listSize = 0;
}

bool arrayList::empty()
{
	return (listSize == 0);
}

node* arrayList::begin()
{
	return header->next;
}

node* arrayList::end()
{
	return trailer;
}

void arrayList::insert(node* pos, int data)
{
	node* newNode = new node;
	newNode->data = data;
	
	newNode->prev = pos->prev;
	newNode->next = pos;
	pos->prev->next = newNode;
	pos->prev = newNode;

	listSize++;
}

void arrayList::insertFront(int data)
{
	insert(begin(), data);
}

void arrayList::insertBack(int data)
{
	insert(end(), data);
}

void arrayList::eraseFront()
{
	erase(begin());
}

void arrayList::eraseBack()
{
	erase(end()->prev);
}

node* arrayList::erase(node* pos)
{
	if (empty())
	{
		cout << "Empty" << endl;
		return pos;
	}
	if (pos == trailer)
		return pos;

	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	delete pos;
	listSize--;
	return begin();
}

node* arrayList::nextP(node* pos)
{
	if (pos == trailer)
		return pos;

	return pos->next;
}

node* arrayList::prevP(node* pos)
{
	if (pos->prev == header)
		return pos;

	return pos->prev;
}

void arrayList::print()
{
	if (empty())
	{
		cout << "Empty" << endl;
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

void arrayList::find(int data)
{
	int index = 0;
	int check = 0;

	node* curNode = begin();
	while (curNode != trailer)
	{
		if (curNode->data == data)
		{
			check = 1;
			cout << index << ' ';
		}
		curNode = curNode->next;
		index++;
	}

	if (check == 0)
		cout << -1;

	cout << endl;
}

void arrayList::find_max(int arr[])
{
	int max = 0;

}

void arrayList::find_min(int arr[])
{

}


int main(void)
{
	arrayList list;
	node* p = list.begin();

	int testCase;
	cin >> testCase;

	while (testCase--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int data;
			cin >> data;
			list.insert(p, data);
		}

		p = list.begin();
		for (int i = 0; i < n; i++)
		{
			int max = p->data;
			int min = p->data;
			if (i == 0)
			{
				if (max < p->next->data)
					max = p->next->data;

				if (min > p->next->data)
					min = p->next->data;
			}
			else if (i == n - 1)
			{
				if (max < p->prev->data)
					max = p->prev->data;
				
				if (min > p->prev->data)
					min = p->prev->data;
			}
			else
			{
				if (max < p->prev->data)
					max = p->prev->data;

				if (max < p->next->data)
					max = p->next->data;

				if (min > p->prev->data)
					min = p->prev->data;

				if (min > p->next->data)
					min = p->next->data;
			}

			//cout << "max:" << max << endl;
			//cout << "min:" << min << endl;
			cout << max - min << ' ';
			p = list.nextP(p);
		}
		cout << endl;
	}
}