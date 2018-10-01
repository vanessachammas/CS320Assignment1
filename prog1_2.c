#include "prog1_2.h"
#include <stdio.h>
#include <stdlib.h>

STACK* MakeStack(int initialCapacity){
STACK *s = (STACK *)malloc(sizeof(STACK));
s->capacity = initialCapacity;
s->size = 0;
s->data = (int *)malloc(sizeof(int)*initialCapacity);
return s;
}

void Push(STACK *stackPtr, int data){
int i;
if (stackPtr->size < stackPtr->capacity){
stackPtr->data[stackPtr->size++] =data;
}
else {
int *tempArr = (int*)malloc(sizeof(int)*++(stackPtr->capacity));
for(i=0; i < stackPtr -> size; ++i){
tempArr[i] = stackPtr->data[i];
}
stackPtr->data = tempArr;
stackPtr->data[stackPtr->size-1] = data;
}
}

int Pop(STACK *stackPtr){ // int data neccessary?
if (stackPtr-> size == 0){
return -1;
}
else 
//stackPtr->data =stackPtr->data[stackPtr->size-1];
//stackPtr->size--;
//return stackPtr->data;
return stackPtr->data[--(stackPtr->size)];
}

void Grow(STACK *stackPtr){
int i;
stackPtr->capacity = (stackPtr->capacity)*2;
int *tempArr = (int*)malloc(sizeof(int)*stackPtr->capacity);
for(i = 0; i < stackPtr->size; ++i){
tempArr[i] = stackPtr->data[i];
}
stackPtr->data = tempArr;
}









