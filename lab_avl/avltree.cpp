
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
    //Fix the pointers
    print();
    cout << endl;
    *_out << __func__ << " about " << t->key << endl; // Outputs the rotation name (don't remove this)
    cout << endl;
    Node* temp = t->right;
    t->right = temp->left;
    temp->left = t;
    t = temp;

    //Fix the heights
    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
    t->left->height = max(heightOrNeg1(t->left->left),
            heightOrNeg1(t->left->right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    *_out << __func__ << " about " << t->key << endl; // Outputs the rotation name (don't remove this)
    cout << endl;
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    //Fix the pointers
    print();
    cout << endl;
    *_out << __func__ << " about " << t->key << endl; // Outputs the rotation name (don't remove this)
    cout << endl;
    Node* temp = t->left;
    t->left = temp->right;
    temp->right = t;
    t = temp;

    //Fix the heights
    t->height = max(heightOrNeg1(t->right), heightOrNeg1(t->left)) + 1;
    t->right->height = max(heightOrNeg1(t->right->right),
            heightOrNeg1(t->right->left)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    *_out << __func__ << " about " << t->key << endl; // Outputs the rotation name (don't remove this)
    cout << endl;
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    if(subtree == NULL)
        return;

    int balance = heightOrNeg1(subtree->right) - heightOrNeg1(subtree->left);
    if(balance == -2){
        int leftBalance = heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left);
        if(leftBalance == -1)
            rotateRight(subtree);
        else
            rotateLeftRight(subtree);
    }
    else if(balance == 2){
        int rightBalance = heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left);
        if(rightBalance == 1)
            rotateLeft(subtree);
        else
            rotateRightLeft(subtree);
    }
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    if(subtree == NULL)
        subtree = new Node(key, value);
    else if(key < subtree->key){
        insert(subtree->left, key, value);
        rebalance(subtree);
    }
    else if(key > subtree->key){
        insert(subtree->right, key, value);
        rebalance(subtree);
    }
    subtree->height = max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) + 1;
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
        remove(subtree->left, key);
    } else if (key > subtree->key) {
        remove(subtree->right, key);
    } else {
        doRemoval(subtree, key);
    }

    rebalance(subtree);
}

template<class K, class V>
typename AVLTree<K, V>::Node*& AVLTree<K, V>::rightMostChild(Node* &subroot){
    if(subroot->right == NULL)
        return subroot;
    return rightMostChild(subroot->right);
}

template<class K, class V>
void AVLTree<K, V>::doRemoval(Node* &subtree, const K& key){
    if (subtree->left == NULL && subtree->right == NULL) {
        noChildRemove(subtree);
    } else if (subtree->left != NULL && subtree->right != NULL) {
        twoChildRemove(subtree, key);
    } else {
        oneChildRemove(subtree);
    }
}

template<class K, class V>
void AVLTree<K, V>::noChildRemove(Node* &subroot){
    delete subroot;
    subroot = NULL;
}

template<class K, class V>
void AVLTree<K, V>::oneChildRemove(Node* &subroot){
    Node* temp = subroot;
    if(subroot->left == NULL)
        subroot = subroot->right;
    else
        subroot = subroot->left;
    delete temp;
}

template<class K, class V>
void AVLTree<K, V>::twoChildRemove(Node* &subroot, const K& key){
    Node* iop = rightMostChild(subroot->left);
    swap(subroot, iop);
    remove(subroot->left, key);
}
