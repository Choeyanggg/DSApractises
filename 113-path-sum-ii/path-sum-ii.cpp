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
    vector<vector<int>> res;
    void dfs(TreeNode* root, int target, int curr, vector<int>& path){
        if(!root) return ;
        curr+=root->val;
        path.push_back(root->val);
        if(!root->left && !root->right && curr==target){
            res.push_back(path);
        }
        dfs(root->right,target,curr,path);
        dfs(root->left,target,curr,path);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int curr=0;
        dfs(root,targetSum,curr,path);
        return res;
    }
};