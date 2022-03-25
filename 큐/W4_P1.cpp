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
	return n > capacity; // 큐의 최대크기 capacity 만큼 큐의 사이즈가 도달했다면 가득 찬것임
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
		cout << arr[(rearIndex - 1) % (capacity+1)] << endl; // rearIndex 는 배열의 끝 위치(rear) 칸의 다음 칸을 가리킨다는 점 유의하기!
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
	int test_case;
	cin >> test_case; // N : 큐의 크기, test_case : 테스트케이스 횟수
	arrayQueue _arr(10000);

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
				cout << "True" << endl;
			else
				cout << "False" << endl;
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

