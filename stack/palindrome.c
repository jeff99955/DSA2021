#include <string.h>
#include <stdio.h>
#define MAX 128

int is_palindrome(char *buf, int n) {
    int mid = n / 2;
    for (int i = 0; i < mid; i++)
        if (buf[i] != buf[n - 1 - i])
            return 0;
    return 1;
    //     printf("%c", buf[i]);
    // for (int i = strlen(buf) - 1; i >= mid + (n & 1); i--)
    //     printf("%c", buf[i]);
    
}
int main(){
    char buf[MAX];
    fgets(buf, 128, stdin);
    int n = strlen(buf);
    if (buf[n - 1] == '\n') buf[--n] = '\0';
    int mid = n / 2;
    printf("%s is ", buf);
    printf((is_palindrome(buf, n)) ? "" : "not ");
    printf("a palindrome.\n");
}
