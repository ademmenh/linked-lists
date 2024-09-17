
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

