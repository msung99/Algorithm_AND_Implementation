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
	int n;
public:
	nodeList();
	bool empty();
	int size();

	node* begin();
	node* end();
	void insert(node* pos, int data);
	node* erase(node* pos);

	node* nextP(node* pos);
	node* prevP(node* pos);
	void print();
	void find(int data);
	int getData(node* pos, int check);
};

nodeList::nodeList()
{
	header = new node;
	trailer = new node;
	header->prev = NULL;
	trailer->next = NULL;
	header->next = trailer;
	trailer->prev = header;
	n = 0;
}

bool nodeList::empty()
{
	return (n == 0);
}

int nodeList::size()
{
	return n;
}

node* nodeList::begin()
{
	return header->next;
}

node* nodeList::end()
{
	return trailer;
}

void nodeList::insert(node* pos, int data) // pos 앞에다 삽입
{
	node* newNode = new node;
	newNode->data = data;
	newNode->prev = pos->prev;
	newNode->next = pos;
	pos->prev->next = newNode;
	pos->prev = newNode;
	n++;
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
	else
	{
		node* tmp = pos;
		pos->next->prev = pos->prev;
		pos->prev->next = pos->next;
		delete tmp;
		n--;
		return begin();
	}
}

node* nodeList::nextP(node* pos)
{
	if (pos == trailer)
		return pos;
	else
		return pos->next;
}

node* nodeList::prevP(node* pos)
{
	if (pos == header->next)
		return pos;
	else
		return pos->prev;
}

void nodeList::print()
{
	if (empty())
	{
		cout << "Empty" << endl;
		return;
	}
	node* curNode = header->next;
	while (curNode != trailer)
	{
		cout << curNode->data << ' ';
		curNode = curNode->next;
	}
	cout << endl;
}

void nodeList::find(int data)
{
	node* curNode = header->next;
	int check = false;
	int index = 0;

	while (curNode != trailer)
	{
		if (curNode->data == data)
		{
			cout << index << ' ';
			check = true;
		}
		curNode = curNode->next;
		index++;
	}
	if (!check)
		cout << -1;
	cout << endl;
}

int nodeList::getData(node* p, int check)
{
	int sum = 0;
	sum = p->data;

	if (check == 0) // 리스트 맨앞 2개 원소의 합
	{   // p->prev->data 는 header->data 이므로, header 의 데이터는 제외하고 리스트 맨앞 2개의 데이터만 sum에 더한다 
		sum += p->next->data;
	}

	else if (check == 1)
	{
		// p->next->data 는 trailer->data 이므로, trailer 의 데이터는 제외하고 리스트 맨뒤 2개의 데이터만 sum에 더한다 
		sum += p->prev->data;
	}

	else if (check == 2)  // 리스트의 중간 원소들의 합
	{
		sum += p->next->data;
		sum += p->prev->data;
	}
	return sum;
}

int main(void)
{
	int testCase;
	cin >> testCase;

	while (testCase--)
	{
		nodeList list;
		node* p = list.begin();
		int size;
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			int data;
			cin >> data;
			list.insert(p, data);
		}
		p = list.begin();
		for (int i = 0; i < size; i++)
		{
			if (i == 0)
			{
				cout << list.getData(p, 0) << ' ';  // 첫번째 합산을 구하는 경우(리스트 맨앞 2개 원소의 합)
				p = list.nextP(p);
			}
			else if (i == size-1)
			{
				cout << list.getData(p, 1) << ' '; // 맨 마지막 합산을 구하는 경우(리스트 맨뒤 2개 원소의 합)
				p = list.nextP(p);
			}
			else
			{
				cout << list.getData(p, 2) << ' '; // 그냥 리스트 중간 원소 3개의 합 
				p = list.nextP(p);
			}
		}
		cout << endl;
	}
}
