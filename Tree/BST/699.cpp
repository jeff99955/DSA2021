/* Leetcode 699. Trim a Binary Search Tree 
   https://leetcode.com/problems/trim-a-binary-search-tree/
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
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (not root) return root;
        int &val = root->val;
        if (val < low) 
            return trimBST(root->right, low, high);
        else if (val > high) 
            return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
