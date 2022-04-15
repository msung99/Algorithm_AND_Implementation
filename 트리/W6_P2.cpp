#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
	int data;
	node* parent;
	vector<node*> childList; // 자식 노드들을 가리키는 포인터들을 벡터에 저장

	node(int data, node* parent)
	{
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
private:
	node* root;
	vector<node*> nodeList; // 트리의 노드들의 주소값을 저장하고 있는 벡터 리스트
public:
	Tree(int data);
	int find(int data, vector<node*>& list); // 노드형 포인터들을 저장하는 벡터 리스트에서 data 값을 가지는 노드의 인덱스를 리턴
	void insertNode(int parData, int data); // data 값을 가지는 새로운 노드를 트리에 insert
	void deleteNode(int data); // 트리에서 data 값을 가지고 있는 노드를 삭제
	void printParent(int data); // 트리에서 data 값을 가지고 있는 노드의 부모노드의 데이터 값을 출력
	void printChild(int data); // 트리에서 data 값을 가지고 있는 노드의 자식노드들의 데이터 값들을 출력
	void maxChild(int data); // 트리의 노드들 중에 데이터 최댓값을 출력
	void minChild(int data);
	void printAncestors(int data);
};

Tree::Tree(int data)
{
	node* newNode = new node(data, NULL);
	root = newNode;
	nodeList.push_back(newNode);
}

// 노드형 포인터들을 저장하는 벡터 리스트에서 data 값을 가지는 노드의 인덱스를 리턴
int Tree::find(int data, vector<node*>& list)
{
	for (int i = 0; i < list.size(); i++) 
	{
		if (data == list[i]->data)
			return i;
	}
	return -1;
}

void Tree::insertNode(int parData, int data)
{
	if (find(data, nodeList) != -1)
	{
		cout << -1 << endl;
		return;
	};

	int idx = find(parData, nodeList);
	if (idx == -1)
	{
		cout << -1 << endl;
		return;
	}
	node* parNode = nodeList[idx];
	node* newNode = new node(data, parNode);
	parNode->childList.push_back(newNode);
	nodeList.push_back(newNode);
}

void Tree::deleteNode(int data)
{
	int idx = find(data, nodeList);
	if (idx == -1)
	{
		cout << -1 << endl;
		return;
	}
	node* delNode = nodeList[idx];
	node* parNode = delNode->parent;
	for (int i = 0; i < delNode->childList.size(); i++)
	{
		delNode->childList[i]->parent = parNode;
		parNode->childList.push_back(delNode->childList[i]);
	}
	vector<node*>& child = parNode->childList;
	child.erase(child.begin() + find(data, child));
	delete nodeList[idx];
	return;
}

void Tree::printParent(int data)
{
	int idx = find(data, nodeList);
	if (idx == -1)
	{
		cout << -1 << endl;
		return;
	}
	node* curNode = nodeList[idx];
	node* parNode = curNode->parent;
	cout << parNode->data << endl;
}

void Tree::printChild(int data) {
	int idx = find(data, nodeList);
	if (idx == -1)
	{
		cout << -1 << endl;
		return;
	}
	node* curNode = nodeList[idx];
	if (curNode->childList.size() == 0)
	{
		cout << -1 << endl;
		return;
	}
	for (int i = 0; i < curNode->childList.size(); i++)
		cout << curNode->childList[i]->data << ' ';
	cout << endl;
}

void Tree::maxChild(int data)
{
	int idx = find(data, nodeList);
	if (idx == -1)
	{
		cout << -1 << endl;
		return;
	}
	node* curNode = nodeList[idx];
	if (curNode->childList.size() == 0)
	{
		cout << -1 << endl;
		return;
	}
	int max = -99999;
	for (int i = 0; i < curNode->childList.size(); i++)
	{
		if (max < curNode->childList[i]->data)
			max = curNode->childList[i]->data;
	}
	cout << max << endl;
}

void Tree::minChild(int data)
{
	int idx = find(data, nodeList);
	if (idx == -1)
	{
		cout << -1 << endl;
		return;
	}
	int min = 999999;
	vector<node*> child = nodeList[idx]->childList;
	for (int i = 0; i < child.size(); i++)
	{
		if (min < child[i]->data)
			min = child[i]->data;
	}
	cout << max << endl;
}

// 조상들을 차례대로 순차적으로 올라가면서 데이터 값을 출력
void Tree::printAncestors(int data)
{
	int idx = find(data, nodeList);
	if (idx == -1)
		return;
	node* curNode = nodeList[idx];
	node* parNode = curNode->parent;
	while (true)
	{
		if (parNode == root) // 루트 노드를 만난다면 루트 노드의 데이터값을 출력하고 while문 종료
		{
			cout << parNode->data << ' ' << endl;
			return;
		}
		cout << parNode->data << ' '; // 루트 노드를 만나기 전까지는 계속 쭉 조상노드들을 타고 올라가면서 데이터값 출력
		parNode = parNode->parent;
	}
}

int main(void)
{
	Tree tree(1);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++)
	{
		int parData, childData;
		cin >> parData >> childData;
		tree.insertNode(parData, childData);
	}

	for (int i = 0; i < m; i++)
	{
		int data;
		cin >> data;
		tree.printAncestors(data);
	}
}
