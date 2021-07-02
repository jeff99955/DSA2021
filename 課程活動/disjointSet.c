#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *parent, *size;
int8_t *rank;
int8_t max_rank = __INT8_MAX__+1;

struct Operation {
    int type;
    int arg1;
    int arg2;
};

void makeSet(int x) {
    parent[x] = x;
    size[x] = 1;
    rank[x] = 0;
}

int findNaive(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

int findCompressionRecursive(int x) {
    if (parent[x] != x)
        parent[x] = findCompressionRecursive(parent[x]);
    return parent[x];
}

int findCompressionIterative(int x) {
    int root = x;
    while (parent[root] != root)
        root = parent[root];
    while (parent[x] != root) {
        int p = parent[x];
        parent[x] = root;
        x = p;
    }
    return root;
}

int findSplitting(int x) {
    while (parent[x] != x) {
        int p = parent[x];
        parent[x] = parent[p];
        x = p;
    }
    return x;
}

int findHalving(int x) {
    while (parent[x] != x)
        x = parent[x] = parent[parent[x]];
    return x;
}

void linkNaive(int x, int y) {
    if (x == y)
        return;
    parent[x] = y;
}

void linkBySize(int x, int y) {
    if (x == y)
        return;
    if (size[x] >= size[y])
        parent[y] = x, size[x] += size[y];
    else
        parent[x] = y, size[y] += size[x];
}

void linkByRank(int x, int y) {
    if (x == y)
        return;
    if (rank[x] > rank[y]){
        if(rank[x] > max_rank)
            max_rank = rank[x];
        parent[y] = x;
    }
    else if (rank[x] == rank[y]){
        parent[y] = x, rank[x]++;
        if(rank[x] > max_rank)
            max_rank = rank[x];
    }
    else{
        parent[x] = y;
        if(rank[y] > max_rank)
            max_rank = rank[y];
    }
        
}

int sameSet(int x, int y, int (*find)(int)) {
    return find(x) == find(y);
}

void unite(int x, int y, int (*find)(int), void (*link)(int, int)) {
    link(find(x), find(y));
}

int main() {
    const int numLinkAlgorithm = 3;
    const int numFindAlgorithm = 5;
    const int iteration = 10;
    

    void (*linkAlgorithm[3])(int, int) = {linkNaive, linkBySize, linkByRank};
    char *linkAlgorithmName[3] = {"Naive-Link", "Link-By-Size", "Link-By-Rank"};
    int (*findAlgorithm[5])(int) = {findNaive, findCompressionRecursive, findCompressionIterative, findSplitting, findHalving};
    char *findAlgorithmName[5] = {"Naive-Find", "Find-Compression-Recursive", "Find-Compression-Iterative", "Find-Splitting", "Find-Halving"};

    
    FILE *inputFile = fopen("disjointSetInput.txt", "r");
    int n, m;
    fscanf(inputFile, "%d %d", &n, &m);
    
    fprintf(stderr, "n=%d m = %d\n", n, m);
    struct Operation *operation = malloc(sizeof(struct Operation) * m);
    for (int i = 0; i < m; ++i)
        fscanf(inputFile, "%d %d %d", &operation[i].type, &operation[i].arg1, &operation[i].arg2);
    fclose(inputFile);

    parent = malloc(sizeof(int) * n);
    size = malloc(sizeof(int) * n);
    rank = malloc(sizeof(int8_t) * n);

    double *lapses = malloc(sizeof(double) * iteration);
    int *ans = calloc(m, sizeof(int));

    for (int k1 = 2; k1 < 3; ++k1) {
        for (int k1 = 0; k1 < numLinkAlgorithm; ++k1) {
        for (int k2 = 0; k2 < numFindAlgorithm; ++k2) {
            max_rank = __INT8_MAX__+1;
            if (k1 == 0 && k2 == 0) {
                fprintf(stderr, "%-12s & %-26s : skipped\n", linkAlgorithmName[k1], findAlgorithmName[k2]);
                continue;
            }
            
            double totalLapse = 0.0;
            for (int t = 0; t < iteration; ++t) {
                void (*link)(int, int) = linkAlgorithm[k1];
                int (*find)(int) = findAlgorithm[k2];

                for (int i = 0; i < n; i++)
                    makeSet(i);

                clock_t startTime = clock();
                for (int i = 0; i < m; ++i) {
                    if (operation[i].type == 1)
                        ans[i] += sameSet(operation[i].arg1, operation[i].arg2, find);
                    else
                        unite(operation[i].arg1, operation[i].arg2, find, link);
                }
                clock_t endTime = clock();

                lapses[t] = (double)(endTime - startTime) / CLOCKS_PER_SEC;
                totalLapse += lapses[t];
            }
            double avgLapse = totalLapse / iteration;
            double stdLapse = 0.0;
            for (int i = 0; i < iteration; ++i)
                stdLapse += (lapses[i] - avgLapse) * (lapses[i] - avgLapse);
            stdLapse = sqrt(stdLapse / (iteration - 1));
            fprintf(stderr, "%d|||%-12s \\& %-26s & %.6f & %.6f\\\\\n", max_rank, linkAlgorithmName[k1], findAlgorithmName[k2], avgLapse, stdLapse);
        }
        }
    }
    /*
    for (int i = 0; i < m; ++i) {
        if (ans[i] != 0 && ans[i] != (numLinkAlgorithm * numFindAlgorithm - 1) * iteration) {
            fprintf(stderr, "The answers are inconsistent!\n");
            return 0;
        }
    }
    */
    free(operation);
    free(parent);
    free(size);
    free(rank);
    return 0;
}
