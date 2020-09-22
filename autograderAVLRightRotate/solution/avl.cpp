#include <stdio.h>
#include <stdlib.h>
#include "cpluspluslabs.h"

Node* new_node(int key) 
{
    Node* node = new Node(); 
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; // new node is initially 
                      // added at leaf  
    return(node);  
}  

int max(int a, int b)  
{  
    return (a > b)? a : b;  
}    
// A utility function to get the  
// height of the tree  
int height(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  

Node* insertnb(Node* node, int key)
{
    if (node == NULL)  
        return(new_node(key));  
  
    if (key < node->key)  
        node->left = insertnb(node->left, key);  
    else if (key > node->key)  
        node->right = insertnb(node->right, key);  
    else // Equal keys are not allowed in BST  
        return node;  
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
}

Node *left_rotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
  
    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  
    // Update heights  
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    // Return new root  
    return y;  
}  

Node* insert(Node* node, int key)  
{  
    /* 1. Perform the normal BST insertion */
    if (node == NULL)  
        return(newNode(key));  
  
    if (key < node->key)  
        node->left = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  
    else // Equal keys are not allowed in BST  
        return node;  
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
    /* 3. Get the balance factor of this ancestor  
        node to check whether this node became  
        unbalanced */
    int balance = getBalance(node);  
  
    // If this node becomes unbalanced, then  
    // there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 && key < node->left->key)  
        return rightRotate(node);  
  
    // Right Right Case  
    if (balance < -1 && key > node->right->key)  
        return leftRotate(node);  
  
    // Left Right Case  
    if (balance > 1 && key > node->left->key)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < node->right->key)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    /* return the (unchanged) node pointer */
    return node;  
}  