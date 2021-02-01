#include "calc.h"
#include <stdlib.h>

struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (data*)malloc(stack->capacity * sizeof(data)); 
    return stack; 
} 
  
// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 
  
// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, int type, int info) 
{ 
    if (isFull(stack)) 
        return; 
    data d;
    d.info = info;
    d.type =type;
    stack->array[++stack->top] = d; 
    return;
} 
  
// Function to remove an item from stack.  It decreases top by 1 
data pop(struct Stack* stack) 
{
    data d = {0,0};
    if (isEmpty(stack)) 
        return d; 
    return stack->array[stack->top--]; 
} 