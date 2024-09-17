
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct floatNode
{
    float Value;
    struct floatNode *Next;
} floatNode;

typedef struct floatList
{
    floatNode *H;
    int length;
} floatList;


void funcflaotNodeInit (floatNode *pNode)
{
    pNode->Value = 0.0;
    pNode->Next = NULL;
}

floatNode* funcfloatNodeCreate (float value)
{

    floatNode *vpNew = (floatNode*) malloc(sizeof(floatNode));
    if ( vpNew == NULL )
    {
        printf ("the allocation has failled !\n");
        exit (1);
    }

    funcfloatNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
}
