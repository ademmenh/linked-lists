
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

floatNode* funcfloatNodePointer (floatList List, int index)
{
    if ( index<0 )
    {
        printf ("this function do not supports negative indexing !");
        exit (1);
    }

    if ( List.length-1<index )
    {
        printf ("the index is out the scope !");
        exit (1);
    }

    floatNode *vpCn = List.H;
    int viCn;

    for ( viCn=0; viCn<index; viCn++ )
    {
        vpCn = vpCn->Next;
    }
    
    return vpCn;
}

floatNode* funcfloatNodePointerBefore (floatList List, int index)
{

    floatNode *vpCn;
    int viCn;



    if ( index<0 )
    {
        printf ("this function do not supports negative indexing !");
        exit (1);
    }
    


    if ( index==0 || List.length<index )
    {
        printf ("The index is out the range of the List !");
        exit (1);
    }


    vpCn = List.H;
    for ( viCn=0; viCn<index-1; viCn++ )
    {
        vpCn = vpCn->Next;
    }
    
    return vpCn;

}

void funfloatNodeFree (floatNode *pNode)
{
    pNode->Next = NULL;
    pNode->Value = 0.0;
    free (pNode);
}



void funcfloatListInit (floatList *pList)
{
    pList->H = NULL;
    pList->length = 0;
}

bool funcfloatListIsEmpty (floatList List)
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

void funcfloatListInsert (floatList *pList, int index, float value)
{

    floatNode *vp, *vpTemp, *vpNew;


    if ( index==0 )
    {
        vpTemp = pList->H;
        vpNew = funcfloatNodeCreate(value);
            
        pList->H = vpNew;
        vpNew->Next = vpTemp;
    }
    else
    {
        vp = funcfloatNodePointerBefore (*pList, index);
        vpTemp = vp->Next;
        vpNew = funcfloatNodeCreate (value);

        vp->Next = vpNew;
        vpNew->Next = vpTemp;
    }



    pList->length++;
}

void funcfloatListInsertBeging (floatList *pList, float value)
{
    funcfloatListInsert (pList, 0, value);
}

void funcfloatListInsertEnd (floatList *pList, float value)
{
    funcfloatListInsert (pList, pList->length, value);
}

float funcfloatListat (floatList List, int index)
{
    floatNode *vp = funcfloatNodePointer(List, index);
    return vp->Value;
}


