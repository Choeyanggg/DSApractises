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
    bool dfs(TreeNode* root,int curr, int targetSum){
        if(!root) return 0;
        curr+=root->val;
        if(!root->left && !root->right){
            if(curr==targetSum) return true;
            else return false;
        }
        return dfs(root->left,curr,targetSum) || 
            dfs(root->right,curr,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int curr=0;
        return dfs(root,curr,targetSum);
    }
};