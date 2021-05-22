// A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
// Given the root to a binary tree, count the number of unival subtrees.
// For example, the following tree has 5 unival subtrees:
//    0
//   / \
//  1   0
//     / \
//    1   0
//   / \
//  1   1

// Asked by Google

#include <stdio.h>

struct node
{
    int data;
    struct node *left, *right;
};

typedef enum
{
    false,
    true
} bool;

bool findUniValueST(struct node *root, int *count)
{
    if (root == NULL)
        return true;
    bool right = findUniValueST(root->right, count);
    bool left = findUniValueST(root->left, count);
    //if left or right subtree is not univalued then that subtree is not univalued
    if (right == false || left == false)
        return false;
    //if right node exists and the value is not equal to root's value,again not univalued
    if (root->right && root->right->data != root->data)
        return false;
    //same for left node also.
    if (root->left && root->left->data != root->data)
        return false;
    /*if above possible conditions not satisified then its a univalued subtree.
    Like this we increment as and when there is a univalued subtree*/
    count++;
    /*and return true*/
    return true;
}

//to return count of the univalued subtrees.
int countUniValueST(struct node *root)
{
    int count = 0;
    int *c = &count;
    findUniValueST(root, c);
    return count;
}

//for inserting a new node
struct node *newNode(int data)
{
    // struct node *temp = newNode;
    struct node *temp;
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
    return (temp);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(3);
    root->left->right = newNode(3);
    root->left->left = newNode(3);
    printf("Number of univalued subtrees: %d", countUniValueST(root));

    return 0;
}