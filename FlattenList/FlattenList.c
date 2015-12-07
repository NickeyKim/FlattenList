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

/*
Starts the beginning of first level
while the first level still not ends
    if CurrentNode has a child
        Add the child at the last of the List
        update Tail pointer
    move to NextNode
*/
 
 
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
