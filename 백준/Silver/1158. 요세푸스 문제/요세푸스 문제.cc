#include <iostream>
#include <string>
using namespace std;

int n, k; // 전역변수로 선언

struct Node{
  int data;
  Node* prev;
  Node* next;
};

class Linkedlist{
public:
  Node* head;
  Node* tail;
  int size = 0; // 링크드 리스트의 크기

  Linkedlist()
  {
    head = NULL;
    tail = NULL;
    size = 0;
  }
 
  // 링크드 리스트 끝에 노드 추가
  void insertNode(int _data)
  {
    Node* newNode = new Node;
    newNode -> data = _data;

    if(!head) // 빈 링크드리스트에 추가 
    {
      head = tail = newNode;
    }
    else
    {
      tail -> next = newNode;
      newNode -> prev = tail;

      tail = newNode; // tail 노드 최신화
    }
    size++; // 리스트 크기 1증가
  }

  // 현재 노드 삭제후 다음 노드를 리턴
  Node* deleteNode(Node* cur) // cur 에 위치한 노드 삭제
  {
    Node* nextNode = cur -> next;
    cur -> prev -> next = cur -> next;
    cur -> next -> prev = cur -> prev;
    
    delete cur; 
    size--; // 리스트 크기 1 감소
    return nextNode; //  다음 노드 리턴
  }

  // 원형 리스트로 만들기
  void makeCircular() 
  {
    tail -> next = head;
    head -> prev = tail;
  }

  // head 노드의 주소 리턴
  Node* getHead()
  {
    return head;
  }

  // 리스트의 크기 리턴
  int getSize()
  {
    return size;
  }
};


int main(void)
{
  cin >> n >> k;

  Linkedlist list;
  

  // 1~n 까지의 원소를 가지는 링크드리스트 생성
  for(int i=1; i<=n; i++){
    list.insertNode(i);
  } 

  list.makeCircular(); // 원형 리스트로 만들기

  cout << "<";

  Node* cur = list.getHead(); // cur 포인터를 head 가 가리키는 위치로 초기화

  while(list.getSize()) // 링크드 리스트의 크기가 0이 되기 전까지 반복
  {
    // k-1 칸 만큼 이동
    for(int i=1; i<k; i++)
    {
      cur = cur -> next;
    }
    
    // 마지막 하나 남은 노드의 데이터를 조회하고, 삭제하려는 경우
    if(list.getSize() == 1)
    {
      cout << cur -> data << ">\n";
      break;
    }
    else
    {
      cout << cur -> data <<", "; 
    }
    // 그곳에 위치한 노드를 삭제
    cur = list.deleteNode(cur);
  }
}