// 싱글리 링크드 리스트 기반의 스택 구현
// (더블리 링크드 리스트 구현은 짜피 안배워서 구현 안해봐도 될듯?)

#include <iostream>
#include <string>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class listStack {
private:
	node* topNode;
	int listSize;
public:
	listStack();
	bool empty();
	int size();
	int top();
	void push(int data);
	void pop();
};

listStack::listStack()
{
	topNode = NULL;
	listSize = 0;
}

bool listStack::empty()
{
	if (listSize == 0)
		return true;
	else
		return false;
}

int listStack::size()
{
	return listSize;
}

int listStack::top()  // top 연산 : O(1)
{
	if (empty())
		return -1;
	else
		return topNode->data;
}

void listStack::push(int data) // push 연산 : head 노드(topNode 노드) 에서 삽입 진행 => O(1)
{
	node* newNode = new node;
	newNode->data = data;

	newNode->next = topNode;
	topNode = newNode;
	listSize++;
}

void listStack::pop() // pop 연산 : 마찬가지로 head 노드에서 삭제 진행 => O(1)
{
	if (empty())
		return;

	node* tmp = topNode;
	topNode = topNode->next;
	delete tmp;
	listSize--;
}