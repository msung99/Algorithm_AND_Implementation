#include <iostream>
#include <string>
using namespace std;

class Node{
private:
  int elem;
  Node* next;
  friend class S_linkedlist;
};

class S_linkedlist{
private:
  Node* head;
  Node* tail;
  int size;

public:
  S_linkedlist()
  {
    size = 0;
    head = NULL;
    tail = NULL;
  }
  void get(int idx);
  void insert(int idx, const int& e);
  void remove(int idx);
  void print();
};


// 인덱스 idx에 노드를 삽입. 
// 기존 인덱스 idx의 노드는 새롭게 idx에 삽입된 노드의 next 노드가 된다.
// (새롭게 idx에 삽입된 노드) -> (기존 idx의 노드) 
void S_linkedlist::insert(int idx, const int& e)
{
  Node* newnode = new Node;
  newnode -> elem = e;
  newnode -> next = NULL;

  if(head == NULL) // 빈 링크드리스트인 경우
  {
    if(idx != 0) // 빈 링크드리스트에서 인덱스 0에 넣어야 삽입이 
    { // 정상적으로 이루어지는데, idx = 0 이 아닌 다른곳에 삽입하려는 경우
      return;
    }
    else // idx = 0 인 경우
    {
      head = tail = newnode;
    }
  }
  else // 빈 링크드리스트가 아닌 경우
  {
    if(idx == 0) // 맨 앞에 넣으려고 할때
    {
      newnode -> next  = head;
      head = newnode;
    }
    else // 중간에 삽입
    {
      Node* scan = head; // 탐색용 노드 scan 설정
      for(int i=0; i< idx-1; i++) // 탐색용 노드를 원하는 인덱스 idx 바로 앞까지 이동시킴
      {
        scan = scan -> next;
      }
      newnode -> next = scan -> next; // newnode 는 인덱스 idx에 있는 노드를 가리킴(즉, idx에 있던 기존 노드는 한칸 뒤로 밀리고, idx 에 newnode가 들어감.)
      scan -> next = newnode; // scan 이 newnode 를 가리킴
    }
  }
  size++;
}

// 인덱스 idx에 위치한 노드 삭제
void S_linkedlist::remove(int idx)
{
  if(head == NULL) // 리스트에 아무것도 없는데 삭제하려고 하면 그냥 종료시킴
  {
    return;
  }
  else
  {
    if(idx == 0)  // head 노드의 데이터 삭제하는 경우
    {
      Node* del = head;
      head = del -> next;
      delete del; // 기존 head 포인터 삭제
    }
    else
    {
      Node* scan = head;
      for(int i=0; i< idx-1; i++) // 삭제하려는 인덱스idx 바로 앞까지 감
      {
        scan = scan -> next;
      }

      Node* target = scan -> next; // target : 삭제하려는 노드
      scan -> next = target -> next; // scan 이 target 의 다음 노드를 가리킴
      delete target; // 삭제할 노드의 노드포인터 삭제
    }
    this -> size--;
  }
}

// 인덱스 idx에 위치한 노드의 데이터값 추출
void S_linkedlist::get(int idx)
{
  Node* scan = head; // 탐색용 노드
  for(int i=0; i <idx; i++){
    scan = scan -> next;
    idx --;
  }
  cout << scan -> elem << endl;
}

void S_linkedlist::print()
{
  Node* scan = head;
  int s = this -> size;

  if(s == 0) // 빈 링크드리스트인 경우
  {
    cout << "아무것도 없습니다.";
  }
  else
  {
    for(int i=0; i < s; i++)
    {
      cout << scan -> elem << " ";
      scan = scan -> next;
    }
  }
  cout << '\n';
}

int main(void)
{
  S_linkedlist sll;

  int num = 0;
  string order;

  cin >> num;

  for(auto k = 0; k < num; k++)
  {
    cin >> order;
    if(order == "insert")
    {
      int idx = 0, e = 0; // idx : 인덱스 값, e : 노드 데이터값
      cin >> idx >> e;
      sll.insert(idx, e);
    }
    else if(order == "get")
    {
      int idx = 0;
      cin >> idx;
      sll.get(idx);
    }
    else if(order == "remove")
    {
      int idx = 0;
      cin >> idx;
      sll.remove(idx);
    }
    else if(order == "print")
    {
      sll.print();
    }
  }
}
