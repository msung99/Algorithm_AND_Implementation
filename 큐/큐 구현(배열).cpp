#include <iostream>
using namespace std;

# define MAX 99999


// 원형 큐 구현
class Queue {
private:
	int data[MAX]; // 큐 데이터를 저장하는 배열
	int index_front; // 가장 앞 인덱스 ( = head 포인터 )
	int index_back; // 맨 뒤 인덱스   ( = tail 포인터 )
public:
	Queue();
	bool empty();
	void push(int x);
	void pop();
	int front();
	int back();
	int size();
};

Queue::Queue() {
	index_front = 0;
	index_back = 0;
}

bool Queue::empty()
{
	return index_front == index_back;
}

void Queue::push(int x)
{// 배열이 꽉차면 다시 0번 인덱스부터 시작해서 push 를 하는 원형 큐의 특성을 구현
	index_back = (index_back + 1) % MAX;  // 인덱스 MAX-1 까지 가득찼다면, 다시 0번 인덱스 부터 데이터를 삽입 
	data[index_back] = x;
}

void Queue::pop()
{
	index_front = (index_front + 1) % MAX; // head 포인터를 한칸 뒤로 이동시켜서, 마치 삭제된 듯하게 함 
	// (실제로는 메모리에서 삭제되진 않음)
}

int Queue::front()
{
	return data[(index_front + 1) % MAX];
}

int Queue::back()
{
	return data[index_back];
}

int Queue::size()
{
	return (index_back - index_front + MAX) % MAX;
}

int main(void)
{
	Queue q;
	// 1~10 숫자를 큐에 push
	for (int i = 1; i <= 10; i++) {
		q.push(i);
	}

	// 1~4 숫자를 pop
	for (int i = 1; i <= 4; i++) {
		q.pop();
	}

	cout << "size:" << q.size() << '\n'; // 6 

	while (!q.empty())
	{
		cout << "pop:" << q.front() << '\n'; // 삭제할 데이터의 값 ( = 맨 앞 데이터의 값) 을 추출하고
		q.pop(); // 삭제시킴
	}
}





















