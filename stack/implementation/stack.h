#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define T char

typedef struct Node {
    T val;
    struct Node *next;
} node;

node *createNode(T val) {
    node *ret = (node *)malloc(sizeof(node));
    assert(ret && "Allocation failed.\n");
    ret->val = val;
    ret->next = NULL;
    return ret;
}

typedef struct Stack {
    int size;
    node *top;
} stack;

stack *init() {
    stack *S = (stack *)malloc(sizeof(stack));
    S->size = 0;
    S->top = NULL;
    return S;
}

bool empty(stack *S) {
    return (S->size == 0);
}

bool push(stack *S, T val) {
    node *N = createNode(val);
    N->next = S->top;
    S->top = N;
    ++S->size;
    return true;
}

bool pop(stack *S) {
    if (empty(S))
        return false;
    T ret = S->top->val;
    S->top = S->top->next;
    return true;
}

T top(stack *S) {
    assert(!empty(S) && "The stack is empty.\n");
    return S->top->val;
}

void print(const char *msg, stack *S) {
    printf("%s", msg);
    node *iter = S->top;
    while (iter) {
        printf("%c ", iter->val);
        iter = iter->next;
    }
    puts("");
}