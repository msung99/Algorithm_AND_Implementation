#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
	int data;   // 몇번쨰 노드인지 
	int data2;  // 폹더 용량 사이즈 값
	node* parent; 
	vector<node*> childList; 

	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
private:
	node* root; 
	vector<node*> nodeList; 
public:
	int find(int data, vector<node*>& list);
	Tree(int data);
	void insertNode(int parData, int data);
	int postOrder(node* curNode);  // 후위 순회로 진행함
	node* findNode(int data); // 트리에 data 값을 가지는 노드를 탐색후 그 노드를 리턴
	void folderSize(int data, int changeData); //  각 data 노드에다가 폴더의 용량 값을 할당시킴 
};

Tree::Tree(int data)
{
	node* newNode = new node(data, NULL);
	root = newNode;
	nodeList.push_back(root);
}


int Tree::find(int data, vector<node*>& list) {  
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->data == data)
			return i;
	}
	return -1;
}

void Tree::insertNode(int parData, int data) {
	if (find(data, nodeList) != -1) 
	{
		cout << -1 << endl;
		return;
	}

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
	return;
}

node* Tree::findNode(int data)
{
	int idx = find(data, nodeList);
	return nodeList[idx];
}

// 후위순회로 서브트리의 총 폴더 용량을 계산후 출력
int Tree::postOrder(node* curNode)
{
	if (curNode->childList.size() == 0)
		return curNode->data2; 

	int sum = 0;
	for (int i = 0; i < curNode->childList.size(); i++)
	{
		sum += postOrder(curNode->childList[i]); // curNode 노드의 각 서브트리의 폴더 용량의 합산을 sum에다 모두 추가 현재 curNode의 총 용량을 구함
	}
	return sum + curNode->data2; // 각 서브트리의 용량을 sum에 모두 더했다면, 마지막에는 자신의 폴더 용량도 더해야지 총 용량이 된다.
}


void Tree::folderSize(int data, int folderSize) // 각 노드에다 폴더의 용량 데이터 값을 할당
{
	int idx = find(data, nodeList);
	node* curNode = nodeList[idx];
	curNode->data2 = folderSize;
}

int main(void)
{
	int size, n;
	cin >> size >> n;
	
	Tree tree(1);
	
	for (int i = 0; i < size - 1; i++)
	{
		int parData, data;
		cin >> parData >> data;
		tree.insertNode(parData, data);
	}

	// 각 노드에다 폴더의 용량 데이터 값을 할당
	for (int i = 0; i < size; i++) 
	{
		int data, changeData;
		cin >> data >> changeData;
		tree.folderSize(data, changeData);
	}

	// 후위순회로 서브트리의 총 폴더 용량을 계산후 출력
	for (int i = 0; i < n; i++)
	{
		int data;
		cin >> data;
		node* p = tree.findNode(data);
		cout << tree.postOrder(p) << endl;
	}
}