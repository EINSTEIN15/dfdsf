#include "linkedlist.h"
#include <iostream>
using namespace std;

bool removeAt(LinkedList &mylist, int pos)
{int i=0;
  Node *tmp=mylist.head;
 
  
  
  if(tmp->next!=NULL)
    {  
  while(i<pos-1)
    {
      tmp=tmp->next;
      i++;
    }
  
  tmp->next=tmp->next->next;
  return 1;
    }	
  else{
  return 0;
  }}
