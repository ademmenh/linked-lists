
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

intNode* funcintNodePointerBefore (intList List, int index)
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

        if ( List.length==-index )
        {
            printf ("For the programmer, You have to access through the Head of the list !");
            exit (1);
        }

        vpCn = List.H;
        for ( viCn=0; viCn<index; viCn++ )
        {
            vpCn = vpCn->Next;
        }
        return vpCn;
    }
    else
    {
        if ( List.length-1<index )
        {
            printf ("The index is out the range of the List !");
            exit (1);
        }

        if ( index==0 )
        {
            printf ("For the programmer, You have to access through the Head of the list !");
            exit (1);
        }

        vpCn = List.H;
        for ( viCn=0; viCn<index-1; viCn++ )
        {
            vpCn = vpCn->Next;
        }
        return vpCn;
    }
}

void funcintNodeFree (intNode *pNode)
{
    pNode->Next = NULL;
    pNode->Value = 0;
    free (pNode);
}



void funcintListInit (intList *pList)
{
    pList->H = NULL;
    pList->length = 0;
}

bool funcintListIsEmpty (intList List)
{
    if ( List.length==0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void funcintListInsert ( intList *pList, int index, int value )
{
    intNode *vpCn, *vpNew, *vp, *vpTemp;
    int viCn;

    if ( index<0 )
    {
        if ( pList->length<-index )
        {
            printf ("The index is out the range of the List !");
            exit (1);
        }

        if ( -index==pList->length )
        {
            vpTemp = pList->H;
            vpNew = funcintNodeCreate (value);

            pList->H = vpNew;
            vpNew->Next = vpTemp;
        }
        else
        {
            vp = funcintNodePointerBefore (*pList, index);
            vpTemp = vp->Next;
            vpNew = funcintNodeCreate (value);
            vp->Next = vpNew;
            vpNew->Next = vpTemp;
        }
    }
    else
    {
        if ( pList->length<index )
        {
            printf ("The index is out the range of the List !");
            exit (1);
        }



        if ( index==0 )
        {
            vpTemp = pList->H;
            vpNew = funcintNodeCreate (pList);
                
            pList->H = vpNew;
            pList->H->Next = vpTemp;

        }
        else
        {
            vp = funcintNodePointerBefore (*pList, index);
            vpTemp = vp->Next;
            vpNew = funcintNodeCreate (value);

            vp->Next = vpNew;
            vpNew->Next = vpTemp;
        }
    }
}



int main ()
{

    // 



    return 0;
}