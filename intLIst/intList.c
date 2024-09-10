
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>





typedef struct intNode
{
    int Value;
    struct intNode *Next;
} intNode;

typedef struct intList
{
    intNode *H;
    int length;
} intList;



void funcintNodeInit (intNode *pNode)
{
    pNode->Value = 0;
    pNode->Next = NULL;
}

intNode* funcintNodeCreate (int value)
{

    intNode *vpNew = (intNode*) malloc (sizeof(intNode));
    if ( vpNew == NULL )
    {
        print ("the allocation has failled !\n");
        exit (1);
    }

    funcintNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
}





int main ()
{

    // 



    return 0;
}