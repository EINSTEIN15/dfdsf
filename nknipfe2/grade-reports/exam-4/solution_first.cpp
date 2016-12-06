#include "common.h"
#include <iostream>
#include <algorithm>

/*
	The algorithm library is included if needed, for the function:
	max: returns the largest of the values passed as arguments.
*/

using namespace std;

Node<int>* deleteNode(Node<int> *&root, int target)
{
  if(root==NULL)
    {
      return NULL;
    }
  if(root!=NULL &&(root->left!=NULL || root->right!=NULL))
    {
  if(root->data==target)
    {
      if(root->left==NULL && root->right==NULL)
	{
	  
	  delete root;
	  root=NULL;

	}
	 if(root->right!=NULL && root->left!=NULL)
	     {
	       Node<int> *tmp=root->right;
	       
	       while(tmp->left!=NULL)
		 {
		   tmp=tmp->left;

		 }
	       int x=tmp->data;
	       delete tmp;
	       tmp=NULL;
	       root->data=x;

	     }
	  if(root->left!=NULL)
	    {
	      int x=root->left->data;
	      delete root->left;
	      root->left=NULL;
	      root->data=x;
	      

	    }

	   if(root->right!=NULL)
	    {

	      int x=root->right->data;
	      delete root->right;
	      root->right=NULL;
	      root->data=x;
	    }
	   
    
	   

    }
    }


  if(target<root->data)
    {
      deleteNode(root->left,target);

    }
  if(target>root->data)
    {

      deleteNode(root->right,target);

    }

}
