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
    int diff=0;
    int findTilt(TreeNode* root) {
        dfs(root);
        return diff;
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        int leftmax=dfs(root->left);
        int rightmax=dfs(root->right);
        diff+=abs(leftmax-rightmax);
        return root->val+rightmax+leftmax;
    }
};