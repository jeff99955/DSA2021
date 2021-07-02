#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int pa[1<<24]; //disjoint set

int c2i(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    else if ('a' <= c && c <= 'z') return c - 'a' + 10;
    else if ('A' <= c && c <= 'Z') return c - 'A' + 36;
    return -1;
}

int hash(const char* s) {
    int ret = 0;
    for (int i = 0; i < 4; ++i)
        ret = (ret << 6) | c2i(s[i]);
    return ret;
}

void makeset(const char* s){
    int i = hash(s);
    // TODO: Initialize a set
}

inline void static init(const char* s) {
    int i = hash(s);
    if (!pa[i]) {
        makeset(s);
        pa[i] = 1;
    }
}

void djsinit(){
	for(int i=0;i<(1<<24);i++)pa[i]=i;
	return;
}

int find_set(int i){
	if(pa[i] != i)
    return pa[i]=find_set(pa[i]);
	else return i;
}

int find_set_string(const char* s) {
    int i = hash(s);
    return find_set(i);
}

void link(const char *ra, const char *rb) {
    int a = find_set_string(ra), b = find_set_string(rb);
    pa[a]=b;
    return;
}

bool same_set(const char *a, const char *b) {
    return (find_set_string(a) == find_set_string(b));
}

bool stringcompare(const char *a, const char *b) {
    // implement your string compare
    char aa[19], bb[19];
    memset(aa, 0, sizeof(aa));
    memset(bb, 0, sizeof(bb));
    if(a[0] == 0 && b[0] == 0) return true;
    for(int i=0;i<4;i++){
    	aa[i] = a[i];
    	bb[i] = b[i];
    }
    if(same_set(aa, bb)){
    	return stringcompare(a+4, b+4);
    }else{
    	return false;
    }
}

int main() {
	djsinit();
    int n;
    scanf("%d", &n);
    char cmd[16], a[512], b[512];
    for (int i = 0; i < n; ++i) {
        scanf("%s %s %s", cmd, a, b);
        if (!strcmp(cmd, "union")) {
            init(a);
            init(b);
            link(a, b);
        } else {
            bool same = stringcompare(a, b);
            if(same) puts("True");
            else puts("False");
        }
    }
}
