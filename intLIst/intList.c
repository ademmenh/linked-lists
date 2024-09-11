
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
        printf ("the allocation has failled !\n");
        exit (1);
    }

    funcintNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
}

intNode* funcintNodePointer (intList List, int index)
{

    intNode *vpCn;
    int viCn;

    if ( index<0 )
    {
        if ( List.length<-index )
        {
            printf ("the index is out the range of the List !");
            exit (1);
        }

        vpCn = List.H;

        for ( viCn=0; viCn<index; viCn++ )
        {
            vpCn = vpCn->Next;
        }
        return vpCn->Value;
    }
    else
    {
        if ( List.length-1<index )
        {
            printf ("The index is out the range of the List !");
            exit (1);
        }

        vpCn = List.H;

        for ( viCn=0; viCn<index; viCn++ )
        {
            vpCn = vpCn->Next;
        }
        return vpCn->Value;
    }
}





int main ()
{

    // 



    return 0;
}