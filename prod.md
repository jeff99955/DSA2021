# Outta the cave

## Spoiler
::: spoiler Click this if and only if you don't got time to read the description
Just finish the TODOs and you're good to go, i.e. The struct of disjoint set, related operations and one line in main function.
:::
## Problem Description
During the spring break of NTU, the class leader of CSIE, NeVer_LoSes (abbreviated NL), along with his friends, went hiking and camping in a remote campsite in Hualien. So mischeivous is NL that he invited his friends to go on an adventure in an attempt to discover some unknown places. They strolled all the way out of the camp zone, and found a mysterious cave with some inlegible handwriting bearing some resemblance to an archaic cuneiform. Discovering deeper into the cave, they missed the way back, but fortunately, a dictionary was hidden under the subterranean lake in the midst of the cave. Scrutinizing the dictionary, NL found out that it is not only a thesaurus but also a record of ancient aboriginals who discovered this secret safe place to avoid their archenemy. To prevent the further pursuit from their enemies or their descendents, they carved some sentences on the path in the cave. To distinguish the correct one to the outer world, it is indicated on the dictionary that the correct paths are the ones with synonyms at both side of the path, while the path to the dead end are not. Please help NL and his friends to find the way out! NL, however, is too lazy to check the inscriptions on the wall and search in the book simultaneously, so he would determine the synonym based on his knowledge, what he memorized when there are no writings on the path, only.

## Input Format
The first line contains integers $N$, denoting the number of operations.
The following $N$ lines are the operations given in the following format:
* `union a b` indicating that `a` and `b` are synonyms.
* `compare A B`: output whether `A` and `B` have the same meaning (i.e. $\text{len}(A) = \text{len}(B)$ and let $A = A_1A_2\ldots A_i\ldots A_{\text{len}(A)}$, $B = B_1B_2\ldots B_i\ldots B_{\text{len}(B)}$,  $(A_i, B_i) \text{ are synonym } \forall i \in [1, \text{len}(A)]$, while $A_i$ and $B_i$ are words.

## Output Format
For each `compare A B`, based on the knowledge of NL, output "True" if `A` and `B` have the same meaning, or "False" otherwise.

## Input Constraint
* Each word (i.e. `a`, `b`) consists of 4 alpha-numeric characters (\^[0-9a-zA-Z]{4}$)
* $0 \leq \text{len}(A), \text{len}(B) \leq 100$ **words**, it is assured that $A$ and $B$ can be uniquely recognized (i.e. words do not overlap)
* Subtask 1 (50%)
    $N \leq 10^3$
> could run in 1 sec using naive
* Subtask 2 (50%)
    $N \leq 10^5$
> could run in 1 sec using path compression and union by rank on linux1, but could exceed 1 sec using oasis1 

## Sample Input
```
4
union nlnl 7414
union mkmk nlnl
compare nlnl7414 7414mkmk
compare nlnl7414 nlnl8787
```
## Sample Output
```
True
False
```
## Sample Code
Constructing a disjoint set forest could help you  solve the problem.
While we encourage you to write your code from scratch, you can refer to the following code and finish the **TODO**s to solve the problem.

``` =c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct DisjointSet{
    // TODO: Determine fields to use by your method
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
    // TODO: Initialize a set
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
    // TODO: Implement your find algorithm here
    return /* something */;
}

void link(const char *ra, const char *rb) {
    int a = find_set(ra), b = find_set(rb);
    // TODO: Implement your union algorithm here
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
        if (!strcmp(cmd, "union")) {
            init(a);
            init(b);
            link(a, b);
        } else {
            int len = strlen(a) / 4;
            bool same = true;
            for (int j = 0; j < len; ++j) {
                if (!same_set(/* what should */, /* be put here */){
                    same = false; break;
                }
            }
            if(same) puts("True");
            else puts("False");
        }
    }
}
```
