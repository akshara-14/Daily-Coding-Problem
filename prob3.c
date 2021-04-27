/* Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.
For example, given the following Node class
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:
node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left' */

// Asked by Google

#include<stdio.h>
#include<stdlib.h>
#define COUNT 10

typedef struct Node{
    char val;
    struct Node *right, *left; 
} Node;

Node* newNode(char key){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = key;
    temp->left = temp->right = NULL;
    return (temp);
}

void serialize(Node* root, char* s, int* i,int n){
    
    if(root!=NULL){
        if(*i<n) serialize(root->left,s,i,n);
        if(*i<n) s[*i] = root->val;
        //printf("%c",s[i]);
        (*i)++;
        if(*i<n) serialize(root->right,s,i,n);
    }
    return;
}

void deserialize(Node** root, char* s, int l, int r){
    if(l>r) return;
    int mid = (l+r)/2;
    *root = newNode(s[mid]);
    deserialize(&((*root)->left),s,l,mid-1);
    deserialize(&((*root)->right),s,mid+1,r);
}

void print2DUtil(struct Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
  
    // Increase distance between levels
    space += COUNT;
  
    // Process right child first
    print2DUtil(root->right, space);
  
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%c\n", root->val);
  
    // Process left child
    print2DUtil(root->left, space);
}

int main(){
    char *s = "abhilash";

    //printf("%s\n",s);
    Node* root;
    deserialize(&root, s, 0, 7);
    print2DUtil(root,0);
    //if(root!=NULL) printf("%c\n",root->left->val);
    char* r;
    int i = 0;
    serialize(root,r,&i,8);
    printf("%s\n",r);
}