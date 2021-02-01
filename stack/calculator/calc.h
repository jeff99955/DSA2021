#ifndef CALC_H
#define CALC_H
typedef struct Data{
    int type; // 0 = number, 1 = symbol
    int info;
}data;

typedef struct Stack { 
    int top; 
    unsigned capacity; 
    data* array; 
}stack; 

  
// function to create a stack of given capacity. It initializes size of 
// stack as 0 
struct Stack* createStack(unsigned capacity); 
  
// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack);
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack);
  
// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, int type, int info) ;
  
// Function to remove an item from stack.  It decreases top by 1 
data pop(struct Stack* stack);


#endif