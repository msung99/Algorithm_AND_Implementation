#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
	node* parent;
	vector<node*> childList;
	int data;

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
	int find(int data, vector<node*> list);
	void insert(int parData, int data);
	void find_ancestor(node* pos1, node* pos2);
	node* getNode(int data);
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

node* Tree::getNode(int data)
{
	int idx = find(data, nodeList);
	return nodeList[idx];
}

void Tree::find_ancestor(node* pos1, node* pos2)
{
	pos1 = pos1->parent;
	pos2 = pos2->parent;
	int count = 0;
	vector<int> pos1_list;
	while (pos1 != NULL)
	{
		pos1_list.push_back(pos1->data);
		pos1 = pos1->parent;
	}
	while (pos2 != NULL)
	{
		for (int i = 0; i < pos1_list.size(); i++)
		{
			if (pos1_list[i] == pos2->data)
			{
				cout << pos2->data;
				return;
			}
		}
		pos2 = pos2->parent;
	}
}

int main(void)
{
	int t, n, m;
	cin >> t;
	while (t--)
	{
		Tree tree(1);
		cin >> n >> m;
		for (int i = 0; i < n-1; i++)
		{
			int data1, data2;
			cin >> data1 >> data2;
			tree.insert(data1, data2);
		}
		while (m--)
		{
			int a, b;
			cin >> a >> b;
			node* p1 = tree.getNode(a);
			node* p2 = tree.getNode(b);
			tree.find_ancestor(p1, p2);
			cout << endl;
		}
	}
}