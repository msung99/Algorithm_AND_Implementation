#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
	int data;
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
	
	void postOrder(node* curNode, int count); // 후위순회 진행 
	node* findNode(int data);
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

// depth = 깊이
void Tree::postOrder(node* curNode, int depth)
{
	for (int i = 0; i < curNode->childList.size(); i++)
	{
		postOrder(curNode->childList[i], depth + 1);
	}
	cout << depth << ' ';
}

int main(void)
{
	int testCase, n;
	cin >> testCase;
	while (testCase--)
	{
		Tree tree(1);
		cin >> n;
		for (int i = 0; i < n - 1; i++)
		{
			int parData, data;
			cin >> parData >> data;
			tree.insertNode(parData, data);
		}

		node* root = tree.findNode(1);
		tree.postOrder(root, 0);
	}
	cout << endl;
}
