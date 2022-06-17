// 기말고사 BST 메소드 내용 : add, minus
// add : x + a, minus : x - a


#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
	int key;
	node* parent;
	node* left;
	node* right;
	node(int key) {
		this->key = key;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
};

class BST {
private:
	node* root;
public:
	BST();
	node* search(node* curNode, int key);
	void insert(int key);
	void remove(int key); // 이 문제에서 삭제연산은 필요x
	void min(int k);
	int get_height(node* sub_root);
	int get_depth(node* cur);
};

BST::BST() {
	root = NULL;
}

node* BST::search(node* curNode, int key) {
	if (curNode == NULL)
		return NULL;

	if (curNode->key == key)  
		return curNode;

	else if (curNode->key < key)   // 현재 노드의 key 가 목표 key보다 작으면
		return search(curNode->right, key); // 오른쪽 자식으로 이동

	else   // 현재 노드의 key 가 목표 key 보다 크면
		return search(curNode->left, key); // 왼쪽 자식으로 이동
}

void BST::insert(int key)
{
	if (search(root, key) != NULL) // 삽입하려는 key 가 이미 트리에 존재하는 경우
		return;

	node* newNode = new node(key);
	if (root == NULL) {  // 아무것도 없는 트리였다면
		root = newNode;  // 삽입할 노드를 루트노드로 지정
		return;
	}

	node* curNode = root;  // 탐색이 끝나면 리프 노드의 자식, 즉 NULL 이 저장될 노드
	node* parNode = NULL;  // 탐색이 끝나면 리프 노드가 저장될 노드

	// search 연산과 유사한 방법으로 루트에서 리프까지 내려온뒤, 리프의 자식으로 새로운 노드를 추가
	// while 문이 끝나면 parNode 에는 리프노드가, curNode 에는 NULL 이 저장된다.
	while (curNode != NULL)
	{
		parNode = curNode;
		if (curNode->key < key)
			curNode = curNode->right;
		else
			curNode = curNode->left;
	}
	
	// 리프노드를 찾았으므로, 리프노드와 삽입할 노드를 서로 이어준다.

	newNode->parent = parNode; // 리프노드인 parNode 를 부모로 설정 
	// 리프 노드의 왼쪽 자식이 될지, 오른쪽 자식이 될지를 설정 
	if (parNode->key < key)
		parNode->right = newNode;

	else
		parNode->left = newNode;
}

void BST::remove(int key) {
	node* delNode = search(root, key);

	if (delNode == NULL) // 삭제하려고 했던 key 값을 가진 노드가 트리에 존재하지 않는 경우 
		return;

	node* parNode = delNode->parent; // 삭제할 노드의 부모
 	node* childNode;  // 삭제할 노드 부모에 새롭게 연결할 자식
	
	
	// 삭제후 연결해줄 자식 노드를 지정해주는 과정

	// Case1. 삭제할 노드가 리프 노드인 경우 (=> 이론시간 내용 : 두 자식이 external 인 경우)
	if (delNode->left == NULL && delNode->right == NULL) {
		childNode = NULL;   //  삭제한 노드의 부모에다 삭제가 안된 나머지 한 external 을 매달아줌
	}                       //  ( => 이론시간 내용 : 아무 external 과 함꼐 한묶음으로 삭제후, 삭제안된 external 자식을 부모에 매달아줌)

	// Case2. 삭제할 노드의 두 자식중 하나가 external 이고, 하나가 internal 인 경우 

	//  왼쪽 자식이 external 인 경우 
	else if (delNode->left == NULL && delNode->right != NULL) {
		childNode = delNode->right;  // 오른쪽 자식인 internal 을 부모에 매달아줌
	}                                //  (=> 이론시간 내용 : external 자식노드와 한묶음으로 삭제후, 나머지 한 internal 자식을 삭제한 노드의 부모와 매달아줌)

	// 오른쪽 자식이 external 인 경우
	else if (delNode->left != NULL && delNode->right == NULL) {
		childNode = delNode->left;
	}

	// Case3. 삭제할 노드의 두 자식이 모두 internal 인 경우
	else {
		// successor 를 childNode 에 저장한다.
		// successor 탐색과정
		childNode = delNode->right;    // 오른쪽 서브트리로 한번 이동후
		while (childNode->left != NULL) {  // 왼쪽으로 계속 파고들음
			childNode = childNode->left;
		}
		// while 문이 끝나면 childNode 는 successor 가 된다.
		delNode->key = childNode->key;  // successor 의 key 값을 덮어씌우고
		// 기존 successor 를 삭제하기 위한 셋팅을 한다.
		delNode = childNode;  // 삭제할 노드를 기존 successor 최신화
		parNode = delNode->parent;  // 삭제할 노드의 부모를 기존 successor 의 부모로 최신화
		childNode = delNode->right;  // 삭제할 노드(successor)의 부모에 매달아줄 노드를 기존 successor의 오른쪽 자식으로 지정
	}
	
	
	// 앞서 삭제를 위해 셋팅한 것들을 기반으로 이제부터 본격적으로 삭제 시작  

	// 삭제할 노드의 부모가 NULL 인경우. 즉, 삭제할 노드가 루트노드인 경우
	if (parNode == NULL) {
		root = childNode;    
		// root->parent = NULL;
	}

	// 왼쪽 자식을 삭제하는 경우
	else if (delNode == parNode->left) {
		parNode->left = childNode;   // 삭제한 노드의 부모의 왼쪽 자식으로 연결
		if (childNode != NULL)    // 연결하려는 자식 노드가 internal 인 경우
			childNode->parent = parNode;  // 이 자식 internal 노드의 부모를 parNode 로 설정
	}
	
	// 오른쪽 자식을 삭제하는 경우
	else {
		parNode->right = childNode;  // 삭제한 노드의 부모의 오른쪽 자식으로 연결
		if (childNode != NULL) // 연결하려는 자식 노드가 internal 인 경우
			childNode->parent = parNode; / 이 자식 internal 노드의 부모를 parNode 로 설정
	}

	delete delNode;
}

// 해당 노드가 루트 노드인 서브트리의 높이 구하기
// main 하수에서 1을 뺸 결과를 출력해야함에 유의하자.
int BST::get_height(node* sub_root) {
	int height = 0;
	if (sub_root != NULL)
	{
		height = 1 + max(get_height(sub_root->left), get_height(sub_root->right));
	}
	return height;
}

// 해당 노드의 깊이 구하기
int BST::get_depth(node* cur) {
	int count = 0;
	while(cur != root)
	{
		cur = cur->parent;
		count++;
	}
	return count;
}
