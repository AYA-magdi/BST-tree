/// INSERT ///
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

class BST
{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    /// if the tree is empty  insert  the first element is <root> --creat newnode --
    /// if tree has root --comper newitem with root is small insert in left --biger insert in right <loop> and <recursion>
    Node *insert(Node *r, int item)
    {
        if (r == NULL)
        {
            Node *newnode = new Node(item);
            r = newnode;
        }
        else if (item < r->data)
        {
            r->left = insert(r->left, item);
        }
        else
        {
            r->right = insert(r->right, item);
        }

        return r;
    }
};