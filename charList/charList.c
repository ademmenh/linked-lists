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
