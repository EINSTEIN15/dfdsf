/**
 * @file list.cpp
 * Singly Linked List (lab_gdb).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 *
 * @author Veer Dedhia
 * @date (modified) Spring 2014
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
#include "list.h"
#include <iostream>
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
    // @todo Graded in lab_gdb
    // Write this function based on mp3
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
    // @todo Graded in lab_gdb
    // Write this function based on mp3
 ListNode *newnode= new ListNode(ndata);
  if(head!=NULL)
    { 
      newnode->next=head;
      // head->prev=newnode;
      head=newnode;
      length++;
    }
  else
    {
      head=newnode;
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
    // @todo Graded in lab_gdb
    // NOTE: Do not use this implementation for MP3!
    ListNode* temp = head;

    if (temp == NULL) {
        head = new ListNode(ndata);
	length++;
    } 
    else {
      while (temp->next != NULL)
	{
            temp = temp->next;
	}
      temp->next= new ListNode(ndata);
      length++;
    }
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    head = reverse(head, NULL, length);
}

/**
 * Helper function to recursively reverse the enitre sequence of
 * linked memory inside a List.
 *
 * @param curr The current node we are reversing
 * @param prev The node that should be placed before the current node in the
 * final reversed list
 * @param len The length of the remaining list to be reversed
 */
template <class T>
typename List<T>::ListNode* List<T>::reverse(ListNode* curr, ListNode* prev,
                                             int len)
{
    // @todo Graded in lab_gdb
    ListNode* temp;
    if(head==NULL)
      {
	return NULL;
      }
    if (len <= 1) {
      curr->next = prev;
        return curr;
    } else {
        temp = reverse(curr->next, curr, len-1);
        curr->next = prev;
        return temp;
    }
    temp=NULL;
    curr=NULL;
    prev=NULL;
}

/**
 * Shuffles the current list by applying a perfect shuffle once. This entails
 * splitting the list in half, then interleaving the two halves.
 * For example:
 * start : < 1, 2, 3, 4, 5 >
 * split : < 1, 2, 3 >    < 4, 5 >
 * final : < 1, 4, 2, 5, 3 >
 */
template <class T>
void List<T>::shuffle()
{
    // @todo Graded in lab_gdb

    // Find the center, and split the list in half
    // one should point at the start of the first half-list
    // two should point at the start of the second half-list
    ListNode *one, *two, *prev, *temp;
      one =head;
      two =head;
      prev =head;
     temp = head;
     ListNode *temp2;
     if(head==NULL)
       {
	 return;


       }
     if(length%2==0){
    for (int i = 0; i < length / 2; i++) {
        prev=two;
        two = two->next;
	
    }
     }
    else
      {
	for (int i = 0; i < (length+1) / 2; i++) {
	  prev=two;
	  two = two->next;



      }
      }
    
    //    ListNode*tmp2;
    
    
    prev->next = NULL;

    // interleave
    while (two!= NULL) {
        temp = one->next;
	
        one->next = two;
        two = two->next;
        one->next->next=temp;
	one=temp;
	
    }
    one=NULL;
    two=NULL;
    prev=NULL;
    temp=NULL;


}
