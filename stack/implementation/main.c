#include "stack.h"

int main()
{
    stack *s = init();
    print("initially: ", s);
    for (int i = 'a'; i <= 'z'; i++)
        push(s, i);
    print("after pushing: ", s);
    for (int i = 0; i < 10; i++)
        pop(s);
    print("after popping 10 elements: ", s);
}