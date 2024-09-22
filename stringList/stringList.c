
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
    int Value;
    struct stringNode *Next;
} stringNode;

typedef struct stringList
{
    stringNode *H;
    int length;
} stringList;



