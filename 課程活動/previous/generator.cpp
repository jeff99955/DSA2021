#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

struct node {
    node *left, *right;
    int val;
    node(int v): val(v) {};
};

node *gen (int val, int c_depth, int t_depth) {
    if (c_depth == t_depth) return nullptr;
    node *n = new node(val);
    n->left = gen(2 * val, c_depth + 1, t_depth);
    n->right = gen(2 * val + 1, c_depth + 1, t_depth);
    return n;
}

void trav(node *root, node *parent) {
    if (not root or not parent) return;
    cout << parent->val << ' ' << root->val << endl;
    trav(root->left, root);
    trav(root->right, root);
}
int main(int argc, char **argv) {
    if(argc < 3) {
        printf("usage: %s depth max\n", argv[0]);
        exit(1);
    }
    int depth = atoi(argv[1]), range = atoi(argv[2]);
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> to_gen(0, 1);
    node *root = gen(1, 0, depth);
    trav(root, root);
}
