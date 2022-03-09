#include <iostream>
using namespace std;

class Node
{
public:
  int value;
  Node* next = NULL;
};

class Stack
{
private:
  Node* head;
  Node* tail;
  int length; // 스택의 크기 
public:
  Stack()
  {
    head = NULL;
    tail = NULL;
    length = 0;
  }
  void push(int value);
  int pop();
  bool empty();
  int top();
  int size();
};

// 스택이 비어있으면 true 리턴
bool Stack::empty()
{
    if(tail == NULL) // 스택이 비어있는 경우
    {
        return true;
    }
    else // 비어있지 않은 경우
    {
        return false; 
    }
}

// 상단 노드의 데이터 값 리턴
int Stack::top()
{
    return tail->value; 
}

int Stack::size()
{
  return length;
}

// 스택에 데이터 추가
void Stack::push(int _value)
{
    Node* newNode = new Node;
    newNode -> value = _value; 
    newNode ->next = NULL;

    // 빈 스택에 새롭게 추가하는 경우
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    
    else
    {
        tail -> next = newNode;
        tail = newNode; // tail 노드 최신화 
    }
    length++; // 스택의 크기 1 증가
}

// 상단 데이터 삭제
int Stack::pop()
{
    // 빈 스택에서 데이터를 삭제하려고 하는 경우
    if(empty())
    {
        return -1; // 삭제할 데이터가 없으므로 삭제하지 않고, -1 을 리턴
    }
    else // 빈 스택이 아닌 경우
    {
        Node* ptr = head;
        int value = head -> value;

        if(head == tail) // case1) 데이터가 딱 하나 남은 경우
        {
            head = NULL;
            tail = NULL;
            delete(head);
            length--; // 스택의 크기 1 감소
        }
        else // case2) 데이터가 하나 남은게 아닌 경우
        {
            while(ptr != NULL) // 반복문을 돌려서 ptr이 tail 노드 직전 위치까지 도달하도록 함
            {
                if(ptr -> next == tail)
                {
                    value = tail -> value; // value에 삭제할 tail 노드의 데이터 값을 저장하고
                    ptr -> next = NULL; // tail 노드 이전노드인 ptr 과 tail 노드의 연결 관계를 끊어버리고
                    delete(tail); // tail 노드를 삭제시킨다
                    tail = ptr; // 그리고 tail 노드를 최신화해준다
                    length--; // 스택의 크기 1감소
                    break; 
                }
                ptr = ptr -> next; // tail 노드 직전 위치를 찾가위해 계속 한칸씩 이동함
            }
            return value; // 삭제한 기존 tail 노드의 데이터 값 리턴
        }
    return value; // case1의 데이터 값을 리턴. 즉, 데이터가 하나 남았을때 삭제한 그 데이터의 값을 리턴
    }
}

int main()
{
  Stack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5); // 1 2 3 4 5 
  cout << stack.top() << endl; // 5
  cout << stack.size() << endl; // 5

  cout << stack.pop() << endl; // 5 
  cout << stack.pop() << endl; // 4
  cout << stack.pop() << endl; // 3
  cout << stack.pop() << endl; // 2
  cout << stack.pop() << endl; // 1
  cout << stack.size() << endl; // 0
  cout << stack.pop() << endl << endl; // -1 리턴
}
