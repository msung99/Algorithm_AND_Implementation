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
public:
	nodeList();
	node* begin();
	node* end();
	void insert(node* pos, int data);
	node* nextP(node* pos);
	node* prevP(node* pos);
};

nodeList::nodeList()
{
	header = new node;
	trailer = new node;

	header->next = trailer;
	trailer->prev = header;

	header->prev = NULL;
	trailer->next = NULL;
}

node* nodeList::begin()
{
	return header->next;
}

node* nodeList::end()
{
	return trailer;
}

void nodeList::insert(node* pos, int data)
{
	node* newNode = new node;
	newNode->data = data;

	pos->prev->next = newNode;
	newNode->prev = pos->prev;
	newNode->next = pos;
	pos->prev = newNode;
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

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		nodeList list;
		node* p = list.begin();
		int count;
		cin >> count;
		for (int i = 0; i < count; i++)
		{
			int data;
			cin >> data;
			list.insert(p, data);
		}

		p = list.begin();
		for (int i = 0; i < count; i++)
		{
			if (count == 1)   // 주의!!!!!! => 리스트 사이즈가 1일때를 따로 처리 해줘야한다!!!
			{
				cout << 0;
				break;
			}

			int max = p->data;
			int min = p->data;
			
			if (i == 0)
			{
				if (max < p->next->data)
					max = p->next->data;

				if (min > p->next->data)
					min = p->next->data;
			}
			else if (i == count - 1)
			{
				if (max < p->prev->data)
					max = p->prev->data;

				if (min > p->prev->data)
					min = p->prev->data;
			}
			else
			{
				if (max < p->next->data)
					max = p->next->data;

				if (max < p->prev->data)
					max = p->prev->data;

				if (min > p->next->data)
					min = p->next->data;

				if (min > p->prev->data)
					min = p->prev->data;
			}

			cout << max - min << ' ';
			p = list.nextP(p);
		}
		cout << endl;
	}
}