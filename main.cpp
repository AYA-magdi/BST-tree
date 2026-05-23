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

void preorder(Node *r) //--root--left--right
{
    if (r == NULL)
        return;
    cout << r->data << "\t";
    preorder(r->left);
    preorder(r->right);
}
void inorder(Node *r) //--left--root--right
{
    if (r == NULL)
        return;
    inorder(r->left);
    cout << r->data << "\t";
    inorder(r->right);
}
void postorder(Node *r) //--left--right--root
{
    if (r == NULL)
        return;
    postorder(r->left);
    postorder(r->right);
    cout << r->data << "\t";
}

Node *search(Node *r, int key)
{
    if (r == NULL)
    {
        return NULL;
    }
    else if (r->data == key)
    {
        return r;
    }
    else if (key < r->data)
    {
        return search(r->left, key);
    }
    else
    {
        return search(r->right, key);
    }
}