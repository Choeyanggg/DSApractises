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
    int path=0;
    int check(TreeNode* root){
        if(!root) return 0;
        int left=check(root->left);
        int right=check(root->right);
        int leftcheck=0, rightcheck=0;
        if(root->left!=nullptr && root->val==root->left->val) leftcheck=left+1;
        if(root->right!=nullptr && root->val==root->right->val) rightcheck=right+1;
        path=max(path,leftcheck+rightcheck);
        return max(leftcheck,rightcheck);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        check(root);
        return path;
    }
};