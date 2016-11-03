#include "common.h"
#include <iostream>

using namespace std;

void updateSum(Node<int> *&root)
{ 


  
  
  int x;
 
  if(root==NULL)
    {
      return;


    }
  updateSum(root->left);
  updateSum(root->right);
  if(root->left!=NULL && root->right!=NULL)
    {

      x=root->left->data+root->right->data;

      root->data=x+root->data;
    }
  if(root->left!=NULL && root->right==NULL)
    {
      x=root->left->data;
      root->data=root->data+x;



    }
    if(root->left==NULL && root->right!=NULL)
      {

	x=root->right->data;
	root->data=x+root->right->data;


      }
   return;
}
