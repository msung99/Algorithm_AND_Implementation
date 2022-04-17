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
	Tree(int data);
	int find(int data, vector<node*> nodeList);
	void insert(int parData, int data);
	void inOrder(node* pos, int count);
	node* get_node(int data);
};

Tree::Tree(int data)
{
	root = new node(data, NULL);
	nodeList.push_back(root);
}

int Tree::find(int data, vector<node*> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (data == list[i]->data)
			return i;
	}
	return -1;
}

void Tree::insert(int parData, int data)
{
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
}

void Tree::inOrder(node* pos, int count)
{
	cout << count << ' ';
	for (int i = 0; i < pos->childList.size(); i++)
	{
		inOrder(pos->childList[i], count + 1);
	}
}

node* Tree::get_node(int data)
{
	int idx = find(data, nodeList);
	return nodeList[idx];
}

int main(void)
{
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		Tree tree(1);
		int n;
		cin >> n;
		for (int i = 0; i < n - 1; i++)
		{
			int data1, data2;
			cin >> data1 >> data2;
			tree.insert(data1, data2);
		}
		node* curNode = tree.get_node(1);
		tree.inOrder(curNode, 0);
		cout << endl;
	}
}