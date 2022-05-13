#include <iostream>
#include <vector>
using namespace std;

struct node {
	int key;
	node* parent;
	node* left;
	node* right;
	node(int key) {
		this->key = key;
		parent = left = right = NULL;
	}
};

class BST {
private:
	node* root;
public:
	BST();
	node* search(node* curNode, int key);
	node* get_node(int key);
	void insert(int key);
	// void remove(int key);
	int size(node* parNode);
};

BST::BST()
{
	root = NULL;
}

// 탐색 연산
// 1. 목표 값이 현재 노드의 key 와 같으면 탐색 종료 (탐색 성공한 것임)
// 2. 목표 값이 현재 노드의 key 보다 작으면 왼쪽 자식으로 이동하여 탐색
// 3. 목표 값이 현재 노드의 key 보다 크면 오른쪽 자식으로 이동하여 탐색


// 목표 key 를 가지는 노드의 포인터를 리턴;
node* BST::search(node* curNode, int key) {
	if (curNode == NULL)  // key 값을 가지는 노드를 찾지 못하면(= external 노드라면) NULL 을 리턴
		return NULL;

	if (curNode->key == key) // 현재 노드의 key 값이 목표 key 값과 일치하는 경우
		return curNode;  // 리턴하면 끝

	else if (curNode->key < key)   // 현재 노드의 key 값보다 목표 key값이 더 큰 경우
		return search(curNode->right, key); // 오른쪽 서브트리로 내려감

	else if (curNode->key > key) // 현재 노드의 key 값보다 목표 key값이 더 작은 경우
		return search(curNode->left, key); // 왼쪽 서브트리로 내려감
}

// 탐색 연산과 유사한 방법으로 루트에서 external 노드까지 내려온 뒤, external 노드의 자식으로 새로운 노드를 추가
void BST::insert(int key) {
	if (search(root, key) != NULL)  // 주어진 key에 해당하는 노드가 이미 존재할 경우, 삽입하지 않고 종료
		return;

	node* newNode = new node(key); // 삽입할 새로운 노드

	if (root == NULL) // 비어있는 이진탐색트리인 경우
	{
		root = newNode; // 삽입할 노드를 루트로 지정
		return;
	}

	node* curNode = root; // 새로 삽입할 노드의 위치를 탐색하는 변수
	node* parNode = NULL; // 새로 삽입할 노드의 부모를 탐색하는 변수

	// 루트에서부터 시작해서 탐색을 진행해서, 새로 삽입할 노드의 위치를 찾아낸다.
	// 정렬의 원리에 따라 리프 노드에 도달 후, 리프 노드의 자식으로 새로운 노드를 추가한다.
	// <=> <이론 수업>TreeSearch() 를 호출해서 정렬의 원리에 따라 external 노드에 도달후, 리턴되는 external 노드 위치에 새로운 노드를 삽입한다.
	while (curNode != NULL) {
		parNode = curNode;
		if (curNode->key < key) {
			curNode = curNode->right;
		}
		else {
			curNode = curNode->left;
		}
	}
	// while 문이 끝나면 curNode 는 NULL이 되고, parNode 는 리프 노드가 되었을 것임. 
	// 즉, NULL 값을 가지는 위치인 curNode 자리에 새로운 노드 newNode 를 삽입한다. newNode 의 부모는 parNode 리프 노드가 되는 것이다.


	// 리프 노드와 새로운 노드를 서로 연결 
	newNode->parent = parNode;
	if (parNode->key < key) {
		parNode->right = newNode;
	}
	else {
		parNode->left = newNode;
	}
}


// curNode 를 루트 노드로 하는 서브트리의 크기를 리턴 
int BST::size(node* curNode)
{
	if (curNode == NULL)
		return 0;

	return size(curNode->left) + size(curNode->right) + 1;
}

// key 값을 가지는 노드의 왼쪽 자식노드를 리턴
node* BST::get_node(int key)
{
	node* parNode = search(root, key);
	return parNode->left;
}

int main(void)
{
	BST b1;
	int n, m;
	cin >> n >> m;
	while (n--)
	{
		int data;
		cin >> data;
		b1.insert(data);
	}

	while (m--)
	{
		int key;
		cin >> key;
		node* curNode = b1.get_node(key); // 왼쪽 서브트리의 루트 노드를 얻어옴
		cout << b1.size(curNode) << endl; // 왼쪽 서브트리의 사이즈를 출력 
	}
}
