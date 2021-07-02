#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct DisjointSet{
    int parent;
    int rank;
} disjoint_set;

disjoint_set ds[1 << 24];
bool set[1 << 24] = {};

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
    ds[i].parent = i;
    ds[i].rank = 1;
}

inline void static init(const char* s) {
    int i = hash(s);
    if (!set[i]) {
        makeset(s);
        set[i] = 1;
    }
}

int find_set(const char* s) {
    init(s);
    int i = hash(s);
    while (ds[i].parent != i) {
        ds[i].parent = ds[ds[i].parent].parent;
        i = ds[i].parent;
    }
    return ds[i].parent;
}

void link(const char *ra, const char *rb) {
    int a = find_set(ra), b = find_set(rb);
    if (a == b) return;
    if (ds[a].rank < ds[b].rank) 
        ds[a].parent = ds[b].parent;
    else {
        if (ds[a].rank == ds[b].rank)
            ds[a].rank++;
        ds[b].parent = ds[a].parent;
    }
}

bool same_set(const char*a, const char* b) {
    return (find_set(a) == find_set(b));
}

int main() {
    int n;
    scanf("%d", &n);
    char cmd[16], a[512], b[512];
    for (int i = 0; i < n; ++i) {
        scanf("%s %s %s", cmd, a, b);
        // int ra = hash(a), rb = hash(b);
        if (!strcmp(cmd, "union")) {
            init(a); 
            init(b);
            link(a, b);
        } else {
            int len = strlen(a) / 4;
            bool same = true;
            for (int j = 0; j < len; j++) {
                // int sa = hash(a + (j * 4)), sb = hash(b + (j * 4));
                if (!same_set(a + (j * 4), b + (j * 4))){
                    same = false;
                    break;
                }
            }
            if(same) puts("True");
            else puts("False");
        }
    }
}
