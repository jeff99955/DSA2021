#include <stdio.h>
#include <string.h>
#define MAX 128

char stack[MAX * 2];
int top = 0;
void push(char c) {stack[top++] = c;}
char pop() { return top ? stack[--top] : '\0'; }
int main()
{
    char s[MAX];
    fgets(s, MAX, stdin);
    s[strlen(s) - 1] = '\0';
    int mid = strlen(s)/2, len = strlen(s), is_valid = 1;
    for(int i=0;s[i] != '\0'; i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            push(s[i]);
        else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
            is_valid &= top && ((s[i] == ')' && pop() == '(')
                        || (s[i] == ']' && pop() == '[')
                        || (s[i] == '}' && pop() == '{'));
    }
    printf("%s is%svalid", s, (is_valid)?" ":" not ");
}