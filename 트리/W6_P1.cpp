#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
	int data;
	node* parent; // 부모 노드를 가리키는 포인터 변수
	vector<node*> childList;  // 자식 노드들을 가리키는 포인터 벡터

	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
private:
	node* root;  // 트리의 root를 저장하는 포인터 변수
	vector<node*> nodeList; // 트리의 모든 노드의 포인터를 저장하는 벡터
public:
	int find(int data, vector<node*>& list); // 노드포인터 벡터에서 특정 노드를 찾는 함수
	Tree(int data);
	void insertNode(int parData, int data); // data를 저장하는 노드를 생성하여 parData의 자식으로 삽입하는 함수
	void deleteNode(int data);  // data를 저장하는 노드를 삭제하는 함수
	void printParent(int data); // data를 저장하는 노드의 부모를 출력하는 함수
	void printChild(int data); // data를 저장하느 노드의 자식들을 출력하는 함수
	void maxChild(int data);
};

Tree::Tree(int data)
{
	node* newNode = new node(data, NULL);
	root = newNode;
	nodeList.push_back(root);
}


int Tree::find(int data, vector<node*>& list) {  // 노드 포인터 벡터에서 특정 노드의 인덱스를 찾는함수
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->data == data) // 노드를 찾았을 경우, 인덱스를 리턴
			return i;
	}
	return -1;
}

// data를 저장하는 노드를 생성하여 parData의 자식으로 삽입하는 함수
void Tree::insertNode(int parData, int data) {
	if (find(data, nodeList) != -1)  // 새로 삽입할 노드(data 노드)가 이미 존재하는 경우
	{
		cout << -1 << endl;
		return;
	}

	int idx = find(parData, nodeList); // nodeList에서 부모 노드의 인덱스를 찾음 
	if (idx == -1)  // 부모 노드(parData 노드)가 존재하지 않는 경우
	{
		cout << -1 << endl;
		return;
	}

	node* parNode = nodeList[idx];
	node* newNode = new node(data, parNode); // 새로 삽입할 노드를 생성하고, 부모를 parNode로 지정
	parNode->childList.push_back(newNode);  // parNode의 자식 벡터 리스트에 newNode를 삽입
	nodeList.push_back(newNode); // 전체 노드 벡터 리스트에 새로운 노드 newNode 를 저장
	return;
}

// data를 저장한 노드를 삭제
void Tree::deleteNode(int data) {
	int idx = find(data, nodeList);
	if (idx == -1)
	{
		cout << -1 << endl;
		return;
	}
	node* delNode = nodeList[idx];
	if (delNode == root)
	{
		cout << -1 << endl;
		return;
	}

	node* parNode = delNode->parent;
	for (int i = 0; i < delNode->childList.size(); i++) {
		parNode->childList.push_back(delNode->childList[i]); // 삭제하려는 노드의 자식들을 parNode의 자식으로 설정
		delNode->childList[i]->parent = parNode; // 삭제하려는 노드의 자식들의 부모를 parNode로 설정
	}
	vector<node*>& child = parNode->childList;
	child.erase(child.begin() + find(data, child)); // 전체 노드 벡터에서 delNode를 제거
	delete nodeList[idx]; // delNode 할당 해제
	return;
}

void Tree::printParent(int data) {   // data를 저장하는 노드의 부모의 데이터를 출력하는 함수 
	int idx = find(data, nodeList);
	if (idx == -1)
	{
		cout << -1 << endl;
		return;
	}
	node* curNode = nodeList[idx];
	cout << curNode->parent->data << endl;
}

// data 값을 가지는 노드에 대한 child의 데이터들을 모두 출력
void Tree::printChild(int data) {
	int idx = find(data, nodeList);
	if (idx == -1)
	{
		cout << -1 << endl;
		return;
	}
	
	vector<node*>& child = nodeList[idx]->childList;
	if (child.size() == 0)
	{
		cout << -1 << endl;
		return;
	}
	for (int i = 0; i < child.size(); i++)
		cout << child[i]->data << " ";
	cout << endl;
}
void Tree::maxChild(int data)
{
	int max = -10000;
	int idx = find(data, nodeList);
	if (idx == -1)
	{
		cout << -1 << endl;
		return;
	}
	vector<node*> child = nodeList[idx]->childList;
	if (child.size() == 0)
	{
		cout << -1 << endl;
		return;
	}

	for (int i = 0; i < child.size(); i++)
	{
		if (max < child[i]->data)
			max = child[i]->data;
	}
	cout << max << endl;
}

int main(void)
{
	Tree tree(1);
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		string command;
		cin >> command;
		if (command == "insert")
		{
			int data1, data2;
			cin >> data1 >> data2;
			tree.insertNode(data1, data2);
		}
		else if (command == "delete")
		{
			int data;
			cin >> data;
			tree.deleteNode(data);
		}
		else if (command == "parent")
		{
			int data;
			cin >> data;
			tree.printParent(data);
		}
		else if (command == "child")
		{
			int data;
			cin >> data;
			tree.printChild(data);
		}
		else if (command == "maxChild")
		{
			int data;
			cin >> data;
			tree.maxChild(data);
		}
	}
}