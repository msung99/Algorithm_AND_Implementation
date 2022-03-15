class Queue {
public:
	Queue();
	~Queue();

	bool empty() const;
	int size() const;
	int front() const;
	void push(const int data);
	int popFront();

	void display() const;

private:
	Node* headNode;
	Node* tailNode;
	int dataSize; // 큐에 저장된 데이터 개수
};

bool Queue::empty() const {
	if (dataSize == 0)
		return 1;
	else
		return 0;
}

int Queue::size() const {
	return dataSize;
}

int Queue::front() const {
	if (empty()) {
		return -1;
	}
	return headNode->getData();
}

void Queue::push(const int data) {
	if (empty())
	{
		headNode = tailNode = new Node(data);
		dataSize++;
		return;
	}
	Node* node = new Node(data, tailNode, NULL); // 새로 할당하려는 노드 node 의 이전 노드를 tail 로, 다음 노드를 NULL 로 설정
	tailNode->setNext(node); // tail 노드의 다음 노드를 node 로 설정
	tailNode = node; // tail 노드 최신화
	dataSize++;
}

int Queue::popFront() {
	int frontData = front(); // 삭제할 노드의 데이터 => 만약에 스택이 비어있으면 에러 발생함
	Node* node = headNode;

	headNode = headNode->getNext(); // head 노드를 한칸 이동

	// headNode == NULL 인 경우 : 스택에서 노드가 딱 하나남은 것을 (head 노드 유일하게 하나였을 때) 삭제하려는 경우
	// 즉, if문의 이 경우는 스택에 노드가 2개 이상 있을 때 삭제를 하는 경우이다.
	if (headNode != NULL)
	{
		headNode->setPrev(NULL); // head 노드의 이전 노드를 NULL 로 설정
	}
	delete node; // 기존 head 노드를 메모리에서 삭제
	dataSize--;
	return frontData; // 삭제한 노드의 데이터 리턴
}

void Queue::display() const {
	if (empty())
	{
		cout << "Queue is empty";
	}
	else
	{
		cout << "size:" << size() << "\n";
		cout << "front:" << front() << "\n";
		for (auto i = headNode; i != NULL; i = i->getNext())
		{
			cout << i->getData() << " ";
		}
		cout << endl;
	}
}

