#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
 
typedef struct node
{
    struct node *prev;
    struct node *next;
    char data;
}node;
 
node *head = NULL;
node *cur = NULL;
 
string s;
int commandNum;
 
void insert(char data)
{
    node *newNode = (node*)malloc(sizeof(node)*1);
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    if(head->next == NULL)
    {
        head->next = newNode;
        newNode->prev = head;
        
        cur = newNode;
    }
    else if(cur->next == NULL)
    {
        newNode->prev = cur;
        cur->next = newNode;
 
        cur = newNode;
    }
    // 중간에 삽입할 경우 
    else if(cur->next != NULL)
    {
        newNode->next = cur->next;
        cur->next->prev = newNode;
        
        cur->next = newNode;
        newNode->prev = cur;
        
        cur = newNode;
    }
}
 
void left()
{
    if(cur->prev != NULL)
    {
        cur = cur->prev;
    }
}
 
void right()
{
    if(cur->next != NULL)
    {
        cur = cur->next;
    }
}
 
void del()
{
    if(cur != head)
    {
        cur->prev->next = cur->next;
        
        // 중간에 삭제하는 경우 
        if(cur->next != NULL)
        {
            cur->next->prev = cur->prev;
        }
        else
        {
            cur->next = NULL;
        }
        
        cur = cur->prev;
    }
}

int main(void)
{
  head = new node;
  head-> next = NULL;
  head-> prev = NULL;

  cin >> s >> commandNum;

  // 리스트 삽입
  for(int i=0; i < s.size(); i++)
  {
    insert(s[i]);
  }

  for(int i=1; i <= commandNum; i++)
  {
    char command;
    cin >> command;

    if(command == 'P')
    {
      char data;
      cin >> data;
      insert(data);
    }
    else if(command == 'L')
    {
      left();
    }
    else if(command == 'D')
    {
      right();
    }
    else if(command == 'B')
    {
      del();
    }
  }

  cur = head -> next;

  // 링크드 리스트 명령어 입력 후 결과 출력
  while(cur != NULL)
  {
    cout << cur -> data;
    cur = cur -> next;
  }
}