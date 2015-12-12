//
//  main.c
//  FlattenList
//
//  Created by NAKHOE KIM on 12/7/15.
//  Copyright © 2015 NAKHOE KIM. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node{
    struct Node *next;
    struct Node *prev;
    struct Node *child;
    int value;
} Node;

/* FlattenList
Starts at the beginning of first level
while the first level still not ends
    if CurrentNode has a child
        Add the child at the last of the List
        update Tail pointer
    move to NextNode
 
- UnFlattenList
 while to the end of the list
    if CurrentNode has a child
        Cut its child from Previous Node
        Search child of child
    move to NextNode
*/
void ExploreAndSeperate ( Node *ChildListStart){
    Node *curNode = ChildListStart;
    
    while (curNode)
    {
        if(curNode->child){
            curNode->child->prev->next = NULL;
            curNode->child->prev= NULL;
            ExploreAndSeperate(curNode->child);
        }
        curNode = curNode->next;
    }
}
void UnFlattenList(Node *head, Node **tail){
    Node *curNode;
    ExploreAndSeperate (head);
    /* Find the new tail, which is the end of the child list */
    for(curNode=head; curNode->next; curNode = curNode->next);  //body be empty
    *tail = curNode;  //update the tail pointer
}

void append( Node *child, Node **tail){
    Node *curNode;
    
    /* Append the child list to the end */
    (*tail)->next = child;
    child->prev = *tail;
    
    /* Find the new tail, which is the end of the child list */
    for(curNode = child; curNode->next; curNode = curNode->next);
    /* Body intenionally empty */
    
    /* Update the tail pointer now that curNode is the new tail */
    *tail = curNode;
}
void FlattenList ( Node *head, Node **tail)
{
    Node *curNode=head;
    while(curNode)
    {
        if(curNode->child){
            append(curNode->child, tail );
        }
        curNode = curNode->next;
    }
}
void printUnFlattenlist ( Node *head)
{
    while (head) {
        printf(" %d", head->value);
        Node *child;
        child= head->child;
        while(child){
            printf("-%d", child->value);
            while(child->child){
                printf("-%d", child->child->value);
                child=child->child;
            }
            child= child->next;
        }
        head = head->next;
    }
    printf("\n");
}
void printFlattenList ( Node *head)
{
    while (head) {
        printf(" %d", head->value);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Node g = { 0, 0,  0, 1 };
    Node e = { 0, 0, 0, 9  };
    Node d = { 0,  0, 0, 6  };
    Node c = { &d, 0, &g ,5 };
    Node b = { &c, 0, 0 , 3 };
    Node a = { &b, 0, &e, 4};
    Node f = { 0, &e, 0, 8};
    Node k = { 0, 0, 0, 7};
    Node h = { 0, 0, &k, 2};

    e.next = &f;
    f.child = &h;
    b.prev = &a;
    c.prev = &b;
    d.prev = &c;
    
    Node *root = &a;
    Node *tail = &d;
    printf("Unflattened List:\n");
    printUnFlattenlist(root);
    FlattenList(root,&tail);
    printf("Flattened List:\n");
    printFlattenList(root);
    
    printf("Unflattened List:\n");
    UnFlattenList(root, &tail);
    printUnFlattenlist(root);
    return 0;
}
