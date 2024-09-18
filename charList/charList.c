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

charNode* funccharNodePointer (charList List, int index)
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

    charNode *vpCn = List.H;
    int viCn;

    for ( viCn=0; viCn<index; viCn++ )
    {
        vpCn = vpCn->Next;
    }
    
    return vpCn;
}

charNode* funccharNodePointerBefore (charList List, int index)
{


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

    charNode *vpCn;
    int viCn;

    vpCn = List.H;
    for ( viCn=0; viCn<index-1; viCn++ )
    {
        vpCn = vpCn->Next;
    }
    
    return vpCn;

}

void funccharNodeFree (charNode *pNode)
{
    pNode->Next = NULL;
    pNode->Value = ' ';
    free (pNode);
}



void funccharListInit (charList *pList)
{
    pList->H = NULL;
    pList->length = 0;
}

bool funccharListIsEmpty (charList List)
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

void funccharListInsert (charList *pList, int index, char value)
{

    charNode *vp, *vpTemp, *vpNew;


    if ( index==0 )
    {
        vpTemp = pList->H;
        vpNew = funccharNodeCreate(value);
            
        pList->H = vpNew;
        vpNew->Next = vpTemp;
    }
    else
    {
        vp = funccharNodePointerBefore (*pList, index);
        vpTemp = vp->Next;
        vpNew = funccharNodeCreate (value);

        vp->Next = vpNew;
        vpNew->Next = vpTemp;
    }



    pList->length++;
}

void funccharListInsertBeging (charList *pList, char value)
{
    funcfloatListInsert (pList, 0, value);
}

void funccharListInsertEnd (charList *pList, char value)
{
    funccharListInsert (pList, pList->length, value);
}

char funccharListat (charList List, int index)
{
    charNode *vp = funccharNodePointer(List, index);
    return vp->Value;
}




