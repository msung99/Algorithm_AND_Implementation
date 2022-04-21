// 리스트의 모든 연산은 O(1) 이 걸린다.
#include <iostream>
#include <string>
using namespace std;

struct node {
	int data;
	node* prev;
	node* next;
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

	node* begin(); // position이 header의 다음 노드를 가리키게 함
	node* end(); //  position이 trailer를 가리키게함

	void insert(node* pos, int data);  // pos가 가리키는 앞쪽에 data를 삽입
	node* erase(node* pos); // pos가 가리키는 원소를 삭제

	void insertFront(int data);
	void eraseFront();
	void insertBack(int data);
	void eraseBack();

	node* nextP(node* pos); // position 을 뒤로 한칸이동
	node* prevP(node* pos); // position 을 앞으로 한칸이동
	void print();
	void find(int data);

	void printp(node* pos);
};

nodeList::nodeList()
{
	header = new node;
	trailer = new node;
	header->next = trailer;
	trailer->prev = header;
	header->prev = NULL;
	trailer->next = NULL;
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

node* nodeList::begin()  // header의 다음 노드를 리턴
{
	return header->next;
}

node* nodeList::end() // trailer 를 리턴
{
	return trailer;
}

void nodeList::insert(node* pos, int data) // O(1)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->prev = pos->prev;
	newNode->next = pos;
	pos->prev->next = newNode;
	pos->prev = newNode;
	n++;
}

void nodeList::insertFront(int data) // O(1)
{
	insert(begin(), data);
}

void nodeList::insertBack(int data) // O(1)
{
	insert(end(), data);
}

node* nodeList::erase(node* pos) // O(1)
{
	if (empty())
	{
		cout << "Empty" << endl;
		return pos;
	}
	else if (pos == trailer)
	{
		return pos;
	}
	else
	{
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		delete pos;
		n--;
		return begin();
	}
}

void nodeList::eraseFront() // O(1)
{
	erase(begin());
}

void nodeList::eraseBack() // O(1)
{
	erase(end()->prev);
}

node* nodeList::nextP(node* pos) // O(1)
{
	if (pos == trailer)
	{
		return pos;
	}
	else
	{
		pos = pos->next;
		return pos;
	}
}

node* nodeList::prevP(node* pos) // O(1)
{
	if (pos == header->next)
	{
		return pos;
	}
	else
	{
		pos = pos->prev;
		return pos;
	}
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
	int index = 0;
	int check = false;
	node* curNode = header->next;
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

void nodeList::printp(node* pos)
{
	cout << pos->data << endl;
}

int main(void)
{
	nodeList list;
	node* p = list.begin();

	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		string command;
		cin >> command;
		if (command == "begin")
		{
			 p = list.begin();
		}
		else if (command == "end")
		{
			p = list.end();
		}
		else if (command == "insert")
		{
			int data;
			cin >> data;
			list.insert(p, data);
		}
		else if (command == "erase")
		{
			p = list.erase(p);
		}
		else if (command == "nextP")
		{
			p = list.nextP(p);
		}
		else if (command == "prevP")
		{
			p = list.prevP(p);
		}
		else if (command == "print")
		{
			list.print();
		}
		else if (command == "find")
		{
			int data;
			cin >> data;
			list.find(data);
		}
		else if (command == "printp")
		{
			list.printp(p);
		}
	}
}




















