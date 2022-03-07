#include <iostream>
#include <string>
using namespace std;

int n;
string str;

struct node{
  char data;
  node* prev, *next = NULL;
};

class linkedlist{
private:
  node* cursor, *head, *tail;

public:
  linkedlist() // 생성자
  {
    head = new node;
    tail = new node;

    head -> next = tail;
    tail -> prev = head;

    cursor = head;
  }

  node* gethead(){
    return head;
  }

  // 커서 포인터 오른쪽에다 노드 삽입
  void enterpass(char _data){
    node* newnode = new node;
    newnode -> data = _data;
    
    cursor->next->prev = newnode;
    newnode -> next = cursor -> next;

    cursor -> next = newnode;
    newnode -> prev = cursor;

    cursor = newnode;
  }

  // 커서 포인터 왼쪽으로 한칸이동
  void moveleft(){
    if(cursor != head)  // cursor 가 head 일때 커서 포인터를 왼쪽으로 이동 불가임
    {
      cursor = cursor->prev; 
    }
  }
 
  // 커서 포인터 오른쪽으로 한칸이동
  void moveright(){
    if(cursor ->next != tail)
    {
      cursor = cursor->next;
    }
  }

  // 커서 포인터의 노드 삭제
  void deletepass(){
    if(cursor != head){ // 커서 포인터가 맨 앞 노드인 head일때 삭제하려고 하면, 삭제할 노드가 없음
      // 생각해보면 cursor->prev 노드가 존재하지 않을 것임.
      cursor->next ->prev = cursor-> prev;
      cursor->prev ->next = cursor->next;  
    
      cursor = cursor -> prev;
    }
  }

  // 링크드 리스트 출력
  void printpass(){
    for(node* temp = head -> next; temp != tail; temp = temp -> next)
    {
      cout << temp -> data;
    }
    cout << '\n';
  }
};

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  
  while(n--) 
  {
    linkedlist pw;

    cin >> str;

    for(int i=0; i<str.size(); i++)
    {
      if(str[i] == '-')
      {
        pw.deletepass();
      }
      else if(str[i] == '<')
      {
        pw.moveleft();
      }
      else if(str[i] == '>')
      {
        pw.moveright();
      }
      else // 명령어가 아닌 그냥 문자인 경우
      {
        pw.enterpass(str[i]);
      }
    }
    pw.printpass(); // 한 문장에대해 명령어 실행이 끝나면 결과를 출력
  }
  return 0;
}
