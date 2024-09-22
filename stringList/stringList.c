
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

void funcstringNodeFree (stringNode *pNode)
{
    funcstringDListClear (&(pNode->Value));
    pNode->Next = NULL;
    
    free (pNode);
}


