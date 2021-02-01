#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "calc.h"
#define MAX 101


int main()
{
    FILE *fp = fopen("result.txt", "w");
    stack *S = createStack(101);
    char operator[101] = {};
    data D[MAX];
    char str[1<<20];
    int count = 0, count_operator = 0;
    fgets(str, 1<<20, stdin);
    /* scan the expression to array */
    char *c = strtok(str, " \n");
    while(c != NULL)
    {
        switch (c[0])
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
            D[count].type = 1;
            D[count].info = c[0];
            count++;
            break;
        default:
            D[count].type = 0;
            D[count].info = atoi(c);
            count++;
            break;
        }
        c = strtok(NULL, " \n");
    }
    /* here str become postfix */
    for(int i = 0; i < count; ++i)
    {
        if(!D[i].type) // numbers
        {
            fprintf(fp, "%d ", D[i].info);
        }
        else
        {
            if(D[i].info == ')')
            {
                while(operator[count_operator - 1] != '(' && count_operator > 0)
                {
                    fprintf(fp, "%c ", operator[count_operator-1]);
                    count_operator--;
                }    
                count_operator--;
            }
            else if (D[i].info == '+' || D[i].info == '-')
            {
                while(operator[count_operator - 1] != '(' && count_operator > 0)
                {
                    fprintf(fp, "%c ", operator[count_operator-1]);
                    count_operator--;
                }
                operator[count_operator++] = D[i].info;
            }
            else if (D[i].info == '*' || D[i].info == '/')
            {
                while((operator[count_operator - 1] == '*' || operator[count_operator - 1] == '/') && count_operator > 0)
                {
                    fprintf(fp, "%c ", operator[count_operator-1]);
                    count_operator--;
                }
                operator[count_operator++] = D[i].info;
            }
            else
                operator[count_operator++] = D[i].info;
        }
    }
    for(int i = count_operator - 1; i >= 0; i--)
    {
        fprintf(fp, "%c ", operator[i]);
    }
    int ret = 0, b, f;
    fclose(fp);
    fp = fopen("result.txt", "r");
    fgets(str, MAX, fp);
    c = strtok(str, " \n");
    while(c != NULL)
    {
        switch (c[0])
        {
        case '+':
            b = pop(S).info;
            f = pop(S).info;
            ret = f + b;
            push(S, 0, ret);
            break;
        case '-':
            b = pop(S).info;
            f = pop(S).info;
            ret = f - b;
            push(S, 0, ret);
            break;
        case '*':
            b = pop(S).info;
            f = pop(S).info;
            ret = f * b;
            push(S, 0, ret);
            break;
        case '/':
            b = pop(S).info;
            f = pop(S).info;
            ret = f / b;
            push(S, 0, ret);
            break;
        //case '(':
        //case ')':
        default:
            push(S, 0, atoi(c));
            break;
        }
        c = strtok(NULL, " \n");
    }
    while(!isEmpty(S))
    {
        data d = pop(S);
        printf("%d\n", d.info);
    }
    
    fclose(fp);
}