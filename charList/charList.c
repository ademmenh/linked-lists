#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct charNode
{
    char Value;
    struct charNode *Next;
} charNode;

typedef struct charList
{
    charNode *H;
    int length;
} charList;

void funccharNodeInit (charNode *pNode)
{
    pNode->Value = ' ';
    pNode->Next = NULL;
}

void funccharNodeFree (charNode *pNode)
{
    pNode->Next = NULL;
    pNode->Value = ' ';
    free (pNode);
}

