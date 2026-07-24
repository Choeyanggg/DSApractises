/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        check(root,diameter);
        return diameter;
    }
    int check(TreeNode* root, int& d){
        if(!root) return 0;
        int left=check(root->left,d);
        int right=check(root->right,d);
        d=max(d,left+right);
        return 1+max(left,right);
    }
};