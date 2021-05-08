/* Leetcode 538. Convert BST to Greater Tree
   https://leetcode.com/problems/convert-bst-to-greater-tree/
   keyword: postorder traversal
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
    Solution() {
        sum = 0;
    }
    TreeNode* convertBST(TreeNode* root) {
        if (not root) return root;
        convertBST(root->right);
        sum += root->val;
        convertBST(root->left);
        return root;
    }
private:
    int sum;
};

int main(){

}