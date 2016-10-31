/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    
    Node * tmp;
    tmp=t->right;
    t->right=tmp->left;
    tmp->left=t;
    
    t->height=max(Height(t->left),Height(t->right))+1;

    tmp->height=max(Height(tmp->left),Height(tmp->right))+1;
    //    t->height=max(Height(t->left),Height(t->right))+1; 
    t=tmp;
      

}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node *& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
        
    Node *tmp;

    tmp=t->left;
    t->left=tmp->right;
    tmp->right=t;
    t->height=max(Height(t->left),Height(t->right))+1;
    tmp->height=max(Height(tmp->left),Height(tmp->right))+1;
    t=tmp;
    


}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);


}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
  //subtree->height=max(Height(subtree->left),Height(subtree->right))+1;
    
  if(subtree->left!=NULL &&subtree->right!=NULL)
    {

  int d=difference(subtree);
  if(d>1)
    {
  
      if(difference(subtree->left)>0)
	{
	  rotateLeft(subtree);
	}
      else
	{
	  rotateLeftRight(subtree);
	}
    }
  if(d<-1)
    {
      if(difference(subtree->right)>0)
	{
	  rotateRightLeft(subtree);

	}
      else
	{

	  rotateRight(subtree);

	}
    }

    }
  


}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
  /*  
  if(root==NULL)
    {
      root=new Node(key,value);
      root->height=0;
    }
  */

insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node *&subtree, const K& key, const V& value )
{ 
  if(subtree==NULL)
    {
      subtree=new Node(key,value);
    }
 
  if(key< subtree->key)
    {
      insert(subtree->left,key,value);
      
    }
  else if(key>subtree->key) 
     {
       insert(subtree->right,key,value);
     }
       
   else
     {
       return;
     }
   subtree->height=max(Height(subtree->left),Height(subtree->right))+1;
  //  rebalance(subtree);

  //rebalance(subtree);
  // rotateRight(subtree);
  int x=difference(subtree);
   if(x >1 && key < subtree->left->key)
    {
      rotateRight(subtree);

    }
   if(x<-1 && key>subtree->right->key)
    {

      rotateLeft(subtree);
    }
  if(x>1 && key>subtree->left->key)
    {
      rotateLeftRight(subtree);
    }
  if(x<-1 && key<subtree->right->key)
    {

      rotateRightLeft(subtree);

      }
}
  
    


template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
      remove(subtree->left,key);
    } else if (key > subtree->key) {
      remove(subtree->right,key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
	  subtree=NULL;
	  
	  



        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
	  Node *tmp=min(subtree->right);
	  subtree->key=tmp->key;
	  remove(subtree->right,tmp->key);

        } else {
            /* one-child remove */
            // your code here
	  Node *tmp=NULL;
	  *subtree=*tmp;
	  delete(subtree);
	  

        }
	subtree->height=max(Height(subtree->left),Height(subtree->right))+1;
	//	rebalance(subtree);

        // your code here
	int x=difference(subtree);
	if(x >1 && key < subtree->left->key)
	  {
	    rotateRight(subtree);

	  }
	if(x<-1 && key>subtree->right->key)
	  {

	    rotateLeft(subtree);
	  }
	if(x>1 && key>subtree->left->key)
	  {
	    rotateLeftRight(subtree);
	  }
	if(x<-1 && key<subtree->right->key)
	  {

	    rotateRightLeft(subtree);

	  }

    
    }
}
template <class K, class V>
int AVLTree<K, V>::Height(Node *node)
{
  if(node==NULL)
    {
      return -1;
    }
  else
    {
  return node->height;
    }
}

template <class K, class V>
int  AVLTree<K, V>::difference(Node *node)
{
  if(node==NULL)
    {
      return 0;
    }
  
  int x=Height(node->left)-Height(node->right);
  return x;

}
template <class K, class V>
typename AVLTree<K, V>::Node* AVLTree<K, V>::min(Node *node)
{
  Node *tmp=node;
  if(tmp->left!=NULL)
    {
      min(tmp->left);
    }
  return tmp;


}



