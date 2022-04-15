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

	void preOrder(node* curNode, int count);
	int postOrder(node* curNode);
	//void inOrder(node* curNode);
	node* getRoot();
	node* getNode(int data); // data 값을 가지는 노드를 리턴
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


void Tree::preOrder(node* curNode, int count) {
	// int count = 0;
	count++;
	cout << count - 1 << ' ';
	for (int i = 0; i < curNode->childList.size(); i++) {
		preOrder(curNode->childList[i], count);
	}
}

/*
int Tree::postOrder(node* curNode, int count) {

	for (int i = 0; i < curNode->childList.size(); i++) {
		postOrder(curNode->childList[i], count);
	}

	if (curNode->childList.size() == 0)
		return count + 2;
}
*/

int Tree::postOrder(node* curNode) {
	int count = 0;
	if (curNode->childList.size() == 0)
		count += 1;
	else {

		for (int i = 0; i < curNode->childList.size(); i++) 
			count += postOrder(curNode->childList[i]);
	}
	return count;
}

node* Tree::getRoot()
{
	return root;
}

node* Tree::getNode(int data)
{
	int idx = find(data, nodeList);

	node* curNode = nodeList[idx];
	return curNode;
}

int main(void)
{
	int folder, file;
	cin >> folder >> file;
	Tree tree(1);
	for (int i = 0; i < folder - 1; i++)
	{
		int parData, data;
		cin >> parData >> data;
		tree.insertNode(parData, data);
	}
	while (file--)
	{
		int file_number;
		cin >> file_number;
		node* cur = tree.getNode(file_number);
		cout << tree.postOrder(cur) << endl;
	}
}