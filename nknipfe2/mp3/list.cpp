/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */

#include <iostream>
using namespace std;

template <class T>
List<T>::~List()
{
  clear();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
  ListNode *currentnode= this->head;
  while (currentnode!=NULL)
    {
      ListNode *nextnode= currentnode->next;
      delete currentnode;
      currentnode=nextnode;

    }


}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const& ndata)
{
  ListNode *newnode= new ListNode(ndata);
  if(head!=NULL)
    { 
      newnode->next=head;
      head->prev=newnode;
      head=newnode;
      length++;
    }
  else
    {
      head=newnode;
      
      tail=head;
      length++;


    }
  newnode=NULL;
  delete newnode;
    
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T& ndata)
{
  ListNode *anothernewnode= new ListNode (ndata);
  if(tail!=NULL)
    {       
      anothernewnode->prev=tail;
      tail->next=anothernewnode;
      tail=anothernewnode;
      anothernewnode=NULL;
      length++;
    }
  else
    { 
      head=anothernewnode;
      tail=anothernewnode;
      length++;
    }
  anothernewnode=NULL;
  //delete anothernewnode;
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    reverse(head, tail);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse( ListNode*& startPoint,  ListNode*& endPoint)
{
  // startPoint=head;
  //endPoint=tail;
   ListNode * current=startPoint;
  ListNode * spot =NULL;
   ListNode * tmp5=NULL;
   ListNode *tmp=endPoint;
   ListNode *tmp2=startPoint;
   ListNode *tmp3=endPoint->next;
   ListNode *tmp4=startPoint->prev;
   ListNode *tmp6;
   if (head==NULL)
     {
       return;
     }

   /*      if(endPoint->next!=NULL || startPoint->prev!=NULL)
     {
       tmp5       = tmp3->prev;
       tmp2->prev = tmp->next;
       tmp3->prev = tmp4->next;
       tmp4->next = tmp5;
       tmp->prev  = tmp2->next;
     }
   *///if(startPoint->prev==NULL && endPoint->next==NULL)
   // {
	 while(current!=tmp3)
	   {
	    spot = current->prev;
	    current->prev = current->next;
	    current->next = spot;              
	    current = current->prev;
       

           }
	  if(spot!=NULL)
	    {startPoint=spot->prev;}
	  if(startPoint==head && endPoint==tail)
	    {tmp6=head;
	      head=tail;
	      tail=tmp6;
	    }
// 



  
     // else 
		 // {
		 /*
		  while(current!=tmp3)
		  {
	   spot = current->prev;
	   current->prev = current->next;
	   current->next = spot;
	   current = current->prev;

	 }
       
	 
       tmp5       = tmp3->prev;
       tmp2->prev = tmp->next;
       tmp3->prev = tmp4->next;
       tmp4->next = tmp5;
       tmp->prev  = tmp2->next;

	 
		 */



       // }






	  /*		  if(endPoint->next!=NULL || startPoint->prev!=NULL)
	   {
	     tmp5=tmp3->prev;
	     tmp2->prev =tmp->next;
	     tmp3->prev =tmp4->next;
	     tmp4->next = tmp5;
	     tmp->prev  = tmp2->next;
	   }
	  */	 

 current=NULL;
 tmp4=NULL;
 tmp3=NULL;
 tmp2=NULL;
 tmp=NULL;
 tmp5=NULL;
}


 
 
 

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth(int n)
{
   ListNode *endpoint=head;
   ListNode *holder=NULL;
   ListNode *holder2=NULL;
   ListNode *startpoint=head;
   int i=0;
   
   //   cout<<"here"<<endl;
   while(endpoint->next!=NULL && i<n)
     { 
       endpoint=endpoint->next;
       i++;

     }
   
   reverse(startpoint,endpoint);
   //   cout<<"here"<<endl; 
   
   
      while(startpoint->next!=NULL)
     {
       holder=startpoint->next;
       cout<<"here"<<endl;
       holder2=holder;
       for(int x=0;holder->next!=NULL && x<n; x++)
	 { holder=holder->next;
	   endpoint=holder->next;
	 }
       cout<<"now"<<endl;
         reverse(holder2,endpoint);
       cout<<"What about"<<endl;
       startpoint=holder2->next;

       }
   
   endpoint=NULL;
   startpoint=NULL;
   }
    


/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall()
{
  ListNode *tmp=head;
  ListNode *tmp2=head;
  ListNode *tmp3=NULL;
  // ListNode *tmp2=tail;
  //ListNode *tmp3=NULL;
  //ListNode *current=head;
  if(head==tail)
    {
      return;
    }
  if(head==NULL && tail==NULL)
    {
      return;
    }

    while(tmp!=NULL && tmp->next!=tail)
      {
       tmp2=tmp;
       tmp =tmp->next;
       tmp3=tmp->next;
       tmp2->next=tmp->next;
       tmp3->prev=tmp2;
       
        tail->next=tmp;
        tmp->prev=tail;
       tmp->next=NULL;
       tail=tmp;
       

       tmp=tmp2->next;


      


      }
       /*   anothernewnode->prev=tail;
      tail->next=anothernewnode;
      tail=anothernewnode*/
    
  //  curr=NULL;
  tmp=NULL;
  tmp2=NULL;
  //current=NULL;
  //tmp2=NULL;
  //tmp3=NULL;
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint)
{
    if (splitPoint > length)
      return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;
    
    ListNode* secondHead = split(head, splitPoint);

    int oldLength = length;
    if (secondHead == head) {
        // current list is going to be empty
        head = NULL;
        tail = NULL;
        length = 0;
    } else {
        // set up current list
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        length = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head = secondHead;
    ret.tail = secondHead;
    if (ret.tail != NULL) {
        while (ret.tail->next != NULL)
            ret.tail = ret.tail->next;
    }
    ret.length = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode* List<T>::split(ListNode* start, int splitPoint)
{
    /// @todo Graded in MP3.2
  ListNode * start2=start;
  int i=0;
  
  while(i<splitPoint)
    {
      start2=start2->next;
      i++;
    }
  start2->prev->next=NULL;
  start2->prev=NULL;
  
return start2; // change me!

}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T>& otherList)
{
    // set up the current list
    head = merge(head, otherList.head);
    tail = head;

    // make sure there is a node in the new list
    if (tail != NULL) {
        while (tail->next != NULL)
            tail = tail->next;
    }
    length = length + otherList.length;

    // empty out the parameter list
    otherList.head = NULL;
    otherList.tail = NULL;
    otherList.length = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode* List<T>::merge(ListNode* first, ListNode* second)
{
  ListNode * tmp=NULL;
  ListNode *tmp2=NULL;
  //ListNode *tmp3=first;
  ListNode *tmp1=first;
  // ListNode *tmp12=first->next
    ListNode *tmp5=second;
    // ListNode *tmp6=second->next;
    ListNode *newlist;
    /// @todo Graded in MP3.2
  /* while(first->next!=NULL)
    {
        tmp=first;
	first=first->next;

    }
  tmp2=first;
  tmp2->next=second;
  tmp2=second->prev;
  return head;

  */

    
    ListNode *lastattached;
    if(first->data<second->data)
      {
	newlist=tmp1;
	tmp1=tmp1->next;
	head=tmp1;
	
      }
    else
      {
	newlist=tmp5;
	tmp5=tmp5->next;
	head=tmp5;
       
      }
    
  
while(tmp1!=NULL && tmp5!=NULL)
      {
	if((tmp1->data)<(tmp5->data))
	  { 
	    newlist->next=tmp1;
	    lastattached=newlist->next;
	    lastattached->prev=newlist;
	    tmp1=tmp1->next;
	    newlist=newlist->next;
	    
	   
	    
	    
	  }
	else
	  { 
	    
	    newlist->next=tmp5;
	    lastattached=newlist->next;
	    lastattached->prev=newlist;
	    tmp5=tmp5->next;
	    newlist=newlist->next;
	    
	    
	  }
       
      }

 if(tmp1!=NULL)
   {
     newlist->next=tmp1;
     tmp1->prev=newlist;
     
   }
 if(tmp5!=NULL)
   {
     newlist->next=tmp5;
     tmp5->prev=newlist;
   }
 if(first->data<second->data)
   {
     return first;
   }
 else
   {
     return second;
   }
 delete tmp5;
/*
      ListNode *tmp5;//=start2;
	ListNode *tmp6;//=start2->next;
     
	while((tmp5->data)<(tmp5->next->data) && tmp5->next!=NULL)
      {
	
	   
	    
	    tmp6->prev=tmp5->prev;
	    tmp5->prev=tmp5->next;
	    tmp5->next=tmp6->next;
	    tmp6->next=tmp5;
	    tmp5=tmp5->next;
	  
	    if(
 
      }
      
 

  while(first->next!=NULL)
    {
        tmp=first;
	first=first->next;

    }
  tmp2=first;
  tmp2->next=second;
  tmp2=second->prev;
*/

  




 // change me!
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort()
{
    if (empty())
        return;
    head = mergesort(head, length);
    tail = head;
    while (tail->next != NULL)
        tail = tail->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode* start, int chainLength)
{    ListNode *start1;
  ListNode *start2;
  if(chainLength==1)
    { 
      return start;
    }
  start1=start;
  start2=split(start,chainLength/2);
  start1=mergesort(start,chainLength/2);
  start2=mergesort(start2,chainLength-chainLength/2);
  
   return merge(start1,start2); // change me!
 }


