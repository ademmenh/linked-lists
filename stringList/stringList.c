
#ifndef _stringLIST_C
    #define _stringLIST_C
#endif

#ifndef _STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef _STDIO_H
    #include <stdio.h>
#endif

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif

#ifndef _STRING_C
    #include "string.c"
#endif





typedef struct stringNode
{
    string Value;
    struct stringNode *Next;
} stringNode;

typedef struct stringList
{
    stringNode *H;
    int length;
} stringList;



void funcstringNodeInit (stringNode *pNode)
{
    funcstringInit (&(pNode->Value));
    pNode->Next = NULL;
}

stringNode* funcstringNodeCreate (string value)
{

    stringNode *vpNew = (stringNode*) malloc(sizeof(stringNode));
    if ( vpNew == NULL )
    {
        printf ("the allocation has failled !\n");
        exit (1);
    }

    funcstringNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
}

stringNode* funcstringNodePointer (stringList List, int index)
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

    stringNode *vpCn = List.H;
    int viCn;

    for ( viCn=0; viCn<index; viCn++ )
    {
        vpCn = vpCn->Next;
    }
    
    return vpCn;
}

stringNode* funcstringNodePointerBefore (stringList List, int index)
{

    stringNode *vpCn;
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

void funcstringNodeFree (stringNode *pNode)
{
    funcstringDListClear (&(pNode->Value));
    pNode->Next = NULL;
    
    free (pNode);
}



void funcstringListInit (stringList *pList)
{
    pList->H = NULL;
    pList->length = 0;
}

bool funcstringListIsEmpty (stringList List)
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

void funcstringListInsert (stringList *pList, int index, string value)
{

    stringNode *vp, *vpTemp, *vpNew;


    if ( index==0 )
    {
        vpTemp = pList->H;
        vpNew = funcstringNodeCreate(value);
            
        pList->H = vpNew;
        vpNew->Next = vpTemp;
    }
    else
    {
        vp = funcstringNodePointerBefore (*pList, index);
        vpTemp = vp->Next;
        vpNew = funcstringNodeCreate (value);

        vp->Next = vpNew;
        vpNew->Next = vpTemp;
    }



    pList->length++;
}

void funcstringListInsertBeging (stringList *pList, string value)
{
    funcstringListInsert (pList, 0, value);
}

void funcstringListInsertEnd (stringList *pList, string value)
{
    funcstirngListInsert (pList, pList->length, value);
}


