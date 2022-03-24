#include <iostream>
#include <string>
using namespace std;

class arrayQueue {
private:
	int* arr;  // 큐의 원소를 저장하는 배열
	int capacity;  // 큐의 최대 크기를 저장하는 변수
	int frontIndex; // 배열에서 큐의 front 위치를 저장하는 변수
	int rearIndex;  // 배열에서 큐의 "rear 위치 + 1" 을 저장하는 변수
	int n; // 큐의 실제 크기를 저장하는 변수
public:
	arrayQueue(int capacity);
	bool isFull();
	bool empty();
	int size();
	void front();
	void rear();
	void enqueue(int data);
	void dequeue();
};

arrayQueue::arrayQueue(int capacity) {
	this->capacity = capacity;
	arr = new int[capacity];
	frontIndex = rearIndex = 0;
	n = 0;
} 

bool arrayQueue::isFull() {
	return n == capacity; // 큐의 최대크기 capacity 만큼 큐의 사이즈가 도달했다면 가득 찬것임
}

bool arrayQueue::empty() {
	return n == 0; // 큐의 실제 사이즈 n의 값이 0이면 비어있는 것임
}

int arrayQueue::size() {
	return n; // 큐의 실제 사이즈 값 리턴
}


// 맨 앞(frontIndex) 의 데이터 값 출력
void arrayQueue::front() {  // 큐의 front에 저장된 원소를 리턴하는 함수
	if (empty())
		cout << "Empty" << endl;
	else {
		cout << arr[frontIndex % capacity] << endl;
	}
}

// 맨 뒤(rearIndex) 의 데이터 값 출력
void arrayQueue::rear() {
	if (empty())
		cout << "Empty" << endl;
	else {
		cout << arr[(rearIndex - 1) % capacity] << endl; // rearIndex 는 배열의 끝 위치(rear) 칸의 다음 칸을 가리킨다는 점 유의하기!
	}
}


void arrayQueue::enqueue(int data) { // 큐의 rear 에 원소를 삽입하는 경우
	if (isFull()) {  // capacity 이상으로 큐에 데이터가 추가되는 것을 방지함
		cout << "FULL" << endl;   //  => 사이즈를 오바해서 enqueue 명령어를 입력받을 경우 그냥 무시하고 하던거 계속 실행함
	}
	// rearIndex 는 배열의 끝 위치(rear) 칸의 다음 칸을 가리킨다는 것을 유의하기!
	else {
		arr[rearIndex] = data;  // 배열의 rearIndex 위치에 원소를 삽입하고, 1증가
		rearIndex = rearIndex + 1;
		n++; // 큐 실제 사이즈 1증가
	}
}

void arrayQueue::dequeue() {
	if (empty())
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << arr[frontIndex] << endl; // 삭제시키려는 맨 앞의 원소 출력
		frontIndex = (frontIndex + 1) % capacity; // 삭제 => front 인덱스를 한칸 이동시킴으로써, 마치 삭제된 듯한 효과를 보임
		n--; // 큐의 실제 사이즈 1감소
	}
}


int main() {
	int N, test_case;
	cin >> N >> test_case; // N : 큐의 크기, test_case : 테스트케이스 횟수

	arrayQueue _arr(N);
	for (int i = 0; i < test_case; i++) {
		string a;
		cin >> a;
		if (a == "isFull") {
			if (_arr.isFull())
				cout << "FULL" << '\n';
			else
				cout << "NOT FULL" << '\n';
		}

		else if (a == "isEmpty") {
			if (_arr.empty())
				cout << "Empty" << endl;
			else
				cout << "Not Empty" << endl;
		}

		else if (a == "dequeue") {
			_arr.dequeue();
		}

		else if (a == "enqueue") {
			int v;
			cin >> v;
			_arr.enqueue(v);
		}

		else if (a == "front") {
			_arr.front();
		}

		else if (a == "rear") {
			_arr.rear();
		}

		else if (a == "size") {
			cout << _arr.size() << '\n';
		}

	}
}

/*
#include <iostream>
#include <string>
using namespace std;

class arrQ {
private:
	// 배열의 시작을 가리키는 포인터 (int형 포인터인것 주의!)
	int* Q;
	// index 정보를 담으므로 pointer 아니라 int형
	// front가 시작 셀 이전의 비어있는 셀을, rear이 마지막 셀을 의미함
	int front = 0;
	int rear = 0;
	int N = 0;
public:
	arrQ(int input_n) {
		// 원형큐이므로 실제 다루는 셀보다 하나 더 큰 배열 필요
		this->N = input_n + 1;
		Q = new int[this->N];
		front = rear = 0;
		for (int i = 0; i < N; i++) {
			Q[i] = 0;
		}
	}
	bool isFull() {
		return (rear + 1) % N == front;
	}
	void isEmpty() {
		string b = (_isEmpty() ? "True" : "False");
		cout << b << endl;
	}
	bool _isEmpty() {
		return front == rear;
	}
	void enqueue(int value) {
		if (isFull()) { cout << "Full" << endl; }
		else {
			// rear은 마지막 원소를 가리키므로 별다른 가공 없어도 됨
			rear = (rear + 1) % N;
			Q[rear] = value;
		}
	}
	void dequeue() {
		if (_isEmpty()) {cout << "Empty" << endl;}
		else {
			// front는 시작셀 이전의 비어있는 셀을 가리키므로 추가 가공 필요
			front = (front + 1) % N; // front를 1 키워서 시작 셀을 가리키게 함
			cout << Q[front] << endl; // 삭제 전에 삭제할 값 출력
			Q[front] = 0; // 시작 셀을 0으로 초기화
			// 이 과정이 끝나도 여전히 front는 시작 셀 이전의 0을 가리키고 있음
		}
	}
	void Front() {
		// Front 함수는 시작 셀을 리턴해야 하므로 인덱스가 front+1인 셀을 리턴해야 함
		if (_isEmpty()) { cout << "Empty" << endl; }
		else cout << Q[(front + 1) % N] << endl;
	}
	void Rear() {
		// rear은 마지막 원소를 가리키므로 별다른 가공 없어도 됨
		if (_isEmpty()) { cout << "Empty" << endl; }
		else cout << Q[rear] << endl;
	}
	void size() {
		// 큐의 실질 크기 n을 리턴 (front 포함 x, 시작~마지막 셀의 개수)
		cout<< (rear - front + N) % N <<endl;
	}
};
int main() {
	int test_case = 0, N = 0;
	cin >> N >> test_case;
	// 앞으로 객체 선언할때 이렇게 하자
	arrQ _arr(N);
	for (int i = 0; i < test_case; i++) {
		string a;
		cin >> a;
		if (a == "isEmpty") {
			_arr.isEmpty();
		}
		else if (a == "dequeue") {
			_arr.dequeue();
		}
		else if (a == "enqueue") {
			int v;
			cin >> v;
			_arr.enqueue(v);
		}
		else if (a == "front") {
			_arr.Front();
		}
		else if (a == "rear") {
			_arr.Rear();
		}
		else if (a == "size") {
			_arr.size();
		}
	}

}
*/
