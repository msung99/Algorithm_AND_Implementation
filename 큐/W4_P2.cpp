
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this -> data = data;
		this->next = NULL;
	}
};

class LinkedQueue {
private:
	int n;
	Node* front;
	Node* rear;
public:
	LinkedQueue() {
		this->front = NULL;
		this->rear = NULL;
		n = 0;
	}

	void enqueue(int data) {
		Node* newNode = new Node(data);
		if (front == NULL) {
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
		n++;
	}

	void dequeue() {
		if (front != NULL) {
			Node* tmp = front;
			front = front->next;
			delete tmp;
		}
		n--;
	}

	int size() {
		return n;
	}

	bool isEmpty() {
		return n == 0;
	}

	int Front() {
		if (isEmpty()) {
			return -1;
		}
		else {
			return this->front->data;
		}
	}

	void Rear() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << this->rear->data << endl;
		}
	}
};

// round : 5
void play(int round, LinkedQueue p1, LinkedQueue p2) {
	for (int k = 0; k < round; k++) {
		int card = 0;
		cin >> card; // 5 => 5개의 카드 

		for (int i = 0; i < card; i++) {
			int n;
			cin >> n;
			p1.enqueue(n); // n=5 => 5개의 카드를 p1에 저장
		}
		for (int i = 0; i < card; i++) {
			int n;
			cin >> n; // n=5 => 5개의 카드를 p2에 저장
			p2.enqueue(n);
		}

		int last_score = 0, winner = 0, p1_score = 0, p2_score = 0;

		for (int j = 0; j < card; j++) {
			// 맞짱뜰 p1_card, p2_card 를 각각 큐에서 뽑음
			int p1_card = p1.Front();
			int p2_card = p2.Front();
			if (winner == 1)
				p1_card += last_score;
			else if (winner == 2)
				p2_card += last_score;

			 // (winner == 1 ? p2_card += last_score : p1_card += last_score);
			if (p1_card > p2_card) { // 플레이어 1이 승리한 경우
				last_score = p1_card - p2_card; // 채력차이 계산
				winner = 1; // 플레이어 1이 이겼다고 표시
				p1_score++; // 플레이어 1의 스코어 증가
			}
			else if (p1_card < p2_card) { // 플레이어 2가 승리한 경우
				last_score = p2_card - p1_card; // 채력차이 계산
				winner = 2;  // 플레이어 2가 이겼다고 표시
				p2_score++; // 플레이어 2의 스코어 증가
			}
			else if(p1_card == p2_card) { // 비긴 경우
				last_score = 0;  // 채력차이는 0
			}

			cout << "Round" << j+1 << " " << p1_score << ":" << p2_score << endl;

			p1.dequeue();
			p2.dequeue();
		}

		if (p1_score > p2_score)
			cout << "Winner P1" << endl;
		else if (p1_score < p2_score)
			cout << "Winner P2" << endl;
		else if (p1_score == p2_score)
			cout << "Draw" << endl;
		//int winner_score = (p1_score >= p2_score ? p1_score : p2_score);
		//cout << winner_score << endl;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	LinkedQueue p1; 
	LinkedQueue p2;
	int round = 0;
	cin >> round;
	play(round, p1, p2);
}















