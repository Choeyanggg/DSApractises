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
    void flatten(TreeNode* root) {
        TreeNode* tail=nullptr;
        dfs(root,tail);
    }
    void dfs(TreeNode* root, TreeNode* & tail){
        if(!root) return;
        TreeNode* right=root->right;
        TreeNode* left=root->left;

        if(tail) tail->right=root;
        root->left=nullptr;
        tail=root;

        dfs(left,tail);
        dfs(right,tail);
    }
};