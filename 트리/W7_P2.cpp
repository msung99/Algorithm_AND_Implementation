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

	void preOrder(node* curNode, int count);
	int postOrder(node* curNode);  // 후위순회 진행 
	node* getRoot();
	node* getNode(int data); 
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


void Tree::preOrder(node* curNode, int count) {
	// int count = 0;
	count++;
	cout << count - 1 << ' ';
	for (int i = 0; i < curNode->childList.size(); i++) {
		preOrder(curNode->childList[i], count);
	}
}


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
