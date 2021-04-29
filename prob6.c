/* An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses. */

// Asked by Google

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    long both;

} StNode;
typedef StNode *pStNode;

pStNode add(pStNode lastNode, int value)
{
    pStNode newNode = (StNode *)malloc(sizeof(StNode));
    newNode->value = value;

    newNode->both = (long)lastNode;
    lastNode->both = (long)newNode ^ lastNode->both;

    return newNode;
}

pStNode get(pStNode headNode, int index)
{
    pStNode prevNode;
    pStNode currNode;
    long tmp;
    //case: cur=1, prev=0
    currNode = (StNode *)((headNode->both) ^ 0);
    prevNode = headNode;

    for (int i = 2; i <= index; i++)
    {
        tmp = (long)prevNode;
        prevNode = currNode;
        currNode = (StNode *)(currNode->both ^ tmp);
    }

    return currNode;
}

int main()
{

    pStNode headNode = (StNode *)malloc(sizeof(StNode));
    headNode->both = 0;
    headNode->value = 2;
    pStNode tailNode = headNode;    

    for (int i = 3; i < 13; i++)
    {
        tailNode = add(tailNode, i);
    }

    pStNode iNode = get(headNode, 3);
    printf("result: %d\n", iNode->value);

    return 0;
}