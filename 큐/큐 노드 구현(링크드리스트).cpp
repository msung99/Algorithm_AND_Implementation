class Node {
public:
	Node(const int data, Node* prev = NULL, Node* next = NULL);

	int getData() const; // 현재 노드의 데이터 리턴
	Node* getPrev() const;// 현재 노드의 이전 노드 리턴
	Node* getNext() const; // 현재 노드의 다음 노드 리턴
	void setData(const int data); // 현재 노드의 데이터값 설정
	void setPrev(Node* node); // 현재 노드의 이전 노드 설정
	void setNext(Node* node); // 현재 노드의 다음 노드 설정

private:
	int data;
	Node* prev;
	Node* next;
};

Node::Node(const int data, Node* prev, Node* next)
{
	this->data = data;
	this->prev = prev;
	this->next = next;
}

int Node::getData() const {
	return data;
}

Node* Node::getPrev() const {
	return prev;
}

Node* Node::getNext() const {
	return next;
}

void Node::setData(const int data) {
	this->data = data;
}

void Node::setPrev(Node* node)
{
	this->prev = node;
}

void Node::setNext(Node* node)
{
	this->next = node;
}
