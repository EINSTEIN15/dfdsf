#include "linkedlist.h"

void alternatingSplit(LinkedList &lst,
    LinkedList* even,
    LinkedList* odd)
{
  Node *tmp= lst.head;
  while(tmp->next!=NULL)
    {
      if(tmp->data%2==0)
	{
	  even=lst;
	  tmp=tmp->next;
	  
	}
      else
	{
	  odd=lst;
	  tmp=tmp->next;

	}
    }
  return odd,even;
}
