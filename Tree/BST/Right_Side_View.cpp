/* Leetcode 199. Binary Tree Right Side View 
   https://leetcode.com/problems/binary-tree-right-side-view/
   keyword: level order traversal
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode *> q;
        vector<int> ret;
        if (root) q.push(root);
        while(q.size()) {
            TreeNode *b = q.back();
            ret.push_back(b->val);
            while (1) {
                TreeNode *f = q.front();
                q.pop();
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
                if (f == b) break;
            }
        }
        return ret;
    }
};
