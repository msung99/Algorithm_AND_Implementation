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
	node* header;  // header 노드를 참조하는 포인터 변수
	node* trailer;  // trailer 노드를 참조하는 포안터 변수
	int n;
public:
	nodeList();
	bool empty();
	int size();

	node* begin();  // 리스트의 첫번째 원소의 주소를 리턴하는 함수
	node* end();  // 리스트의 마지막 원소의 다음 원소를 리턴하는 함수

	void insert(node* pos, int data); // 리스트에서 pos가 가리키는 원소의 앞쪽에 data를 삽입하는 함수
	void insertFront(int data);
	void insertBack(int data);
	node* erase(node* pos); // 리스트에서 pos가 가리키는 원소를 삭제하는 함수
	void eraseFront();
	void eraseBack();

	node* nextP(node* pos); // p를 p가 가리키는 노드의 다음 노드로 이동시킴. (단,p가 trailer를 가리키는 경우, 이동시키지 않는다)
	node* prevP(node* pos); // p를 p가 가리키는 노드의 이전 노드로 이동시킴. (단,p가 header의 다음 노드를 가리키는 경우, 이동시키지 않는다)

	void print(); // header의 다음노드부터 trailer의 이전 노드까지 차례대로 노드의 data를 띄어쓰기로 구분하여 출력(리스트가 비어있다면 "Empty"를 출력)
	void find(int e); // 리스트 내에서 e와 동일한 값이 저장된 노드의 index를 오름차순으로 모두 출력.(노드의 index는 0부터 시작한다)
				   // 리스트 내에 e와 동일한 값이 저장된 노드가 없다면 -1을 출력한다.

	void printp(node* p);
	int getData(node* p);
};

nodeList::nodeList()
{
	header = new node();
	trailer = new node();
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

// 리스트의 맨앞 원소(header의 다음 노드)의 주소를 리턴하는 함수
node* nodeList::begin()
{
	return header->next;
}

// 리스트의 맨뒤 원소(trailer)의 주소를 리턴하는 함수
node* nodeList::end()
{
	return trailer;
}

// 리스트의 pos가 가리키는 노드의 앞쪽에 data를 삽입하는 함수
void nodeList::insert(node* pos, int data)
{
	node* newNode = new node();
	newNode->data = data;

	newNode->prev = pos->prev;
	newNode->next = pos;

	pos->prev->next = newNode;
	pos->prev = newNode;
	n++;
}

// 리스트의 맨앞에 data를 삽입하는 함수
void nodeList::insertFront(int data)
{
	insert(begin(), data);
}

// 리스트의 맨뒤에 data를 삽입하는 함수
void nodeList::insertBack(int data)
{
	insert(end(), data);
}

// 리스트에서 pos가 가리키는 노드를 삭제하는 함수
node* nodeList::erase(node* pos)
{
	// node* new_p = begin();

	node* new_p = pos->prev;

	if (pos == trailer)
	{
		if (empty())
		{
			cout << "Empty" << '\n';
		}

		return pos;
	}

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	delete pos;
	n--;
	return new_p;
}

// 리스트의 맨앞 원소를 삭제
void nodeList::eraseFront()
{
	erase(begin());
}

void nodeList::eraseBack()
{
	erase(end()->prev);
}

node* nodeList::nextP(node* pos)
{
	if (pos == trailer) // p가 trailer를 가리키는 경우, 이동시키지 않는다
		return pos;
	else
	{
		pos = pos->next;
		return pos;
	}
}

node* nodeList::prevP(node* pos)
{
	if (pos->prev == header) // p가 header의 다음 노드를 가리키는 경우(즉, 맨앞 원소를 가리키는 경우) 이동시키지 않는다
		return pos;
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

	node* tmp = new node;
	tmp = header->next;
	while (tmp != trailer)
	{
		cout << tmp->data << ' ';
		tmp = tmp->next;
	}
	cout << '\n';
}

void nodeList::find(int find_data)
{
	int index = 0;
	int check = false; // e와 동일한 값이 저장된 노드가 있는지 체크하는 변수
	node* tmp = new node;
	tmp = header->next;
	while (tmp != trailer)
	{
		if (tmp->data == find_data)
		{
			cout << index << '\n';
			check = true;
		}
		tmp = tmp->next;
		index++;
	}
	if (!check) // e와 동일한 값이 저장되어 있지 않는 경우
		cout << -1 << '\n';
}

void nodeList::printp(node* p)
{
	cout << p->data << '\n';
}

int nodeList::getData(node* p)
{
	int sum = 0;
	sum = p->data;
	sum += p->prev->data;
	sum += p->next->data;

	return sum;
}

int main(void)
{
	int testCase;
	cin >> testCase;

	while (testCase--)
	{
		int n;
		cin >> n;
		nodeList list;
		node* p = list.begin();  // 노드형 포인터 p => position ADT 를 구현해놓은 것

		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			list.insert(p, num);
		}

		p = list.begin();

		for (int i = 0; i < n; i++)
		{
			cout << list.getData(p) << ' ';
			p = list.nextP(p);
		}
		cout << '\n';
	}
}