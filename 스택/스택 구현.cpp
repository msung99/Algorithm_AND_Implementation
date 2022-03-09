#include <iostream>
using namespace std;

const int MAX_NUM = 100;

class Stack{
public:
  int data[MAX_NUM];
  int _top; // 마지막 원소를 가리키는 인덱스
  
  Stack()
  {
    _top = -1; // 초기화
  }

  // 데이터 추가
  void push(int value)
  {
    if(full())
    {
        cout << "stack overflow 에러 발생" << endl;
        exit(-1);
    }
    else
    {
      _top++;
      data[_top] = value;
    }
  }

  // top에 있는 데이터 삭제
  int pop()
  {
    if(empty())
    {
        cout << "stack overflow 에러 발생" << endl;
        exit(-1);
    }
    else
    { // data = {1,2,3,4,5}인 경우 top=4이므로 x = 5 가 저장됨
      // top 을 1 감소키키면 실제 배열 data[4] 메모리에 들어있는 값 5가 
      // 삭제되진 않지만, 어차피 나중에 data[4]에 데이터를 push 하면 
      // 기존에 들어있던 값 5는 새로 들어온 값으로 바뀜   
      int x = data[_top];
      _top--; //  
      return x; // 인덱스 top에 들어있던 데이터 값을 리턴
    }
  }

  // top에 있는 데이터 값을 조회
  int top()
  {
    if(empty())
    {
      cout << "stack overflow 에러 발생" << endl;
      exit(-1);
    }
    else
    {
      return(data[_top]);  
    }
  }
  
  // 스택이 가득찼는지 판별
  bool full()
  {
    // 마지막 원소를 가리키는 인덱스 변수 top의 값이 실제 마지막 인덱스 값 MAX_NUM -1
    // 과 동일하다면 원소가 가득찬 것이다. 
    // 인덱스는 0~99 까지이므로 -1 을 해준다.
    if(_top == MAX_NUM -1)
      return true;
    else
      return false;
  }
  
  // 스택이 비어있는지 판별
  bool empty()
  {
    // 마지막 원소를 가리키는 인덱스 값 top이 -1 이라면 스택이 비어있다는뜻
    if(_top == -1) 
      return true;
    else
      return false;
  }

  // 스택 출력. 스택의 특성에 따라서, top 원소부터 출력한다
  void printStack()
  {
    for(int i = _top; i >= 0; i--)
    {
      cout << data[i] << " ";
    }
    cout << '\n';
  }
};

int main(void)
{
  Stack mystack;

  mystack.push(100);
  mystack.printStack(); // 100 출력

  mystack.pop();
  mystack.printStack(); // x

  mystack.push(200); // 200
  mystack.push(300); // 200 300
  mystack.printStack(); // 300 200 출력

  int key = mystack.pop();  // 200
  mystack.printStack(); // 200 출력

  mystack.push(400); // 200 400 출력
  mystack.printStack(); // 400 200 출력
}