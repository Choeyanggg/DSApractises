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
    int check(TreeNode* root){
        if(!root) return 0;
        int leftmax=check(root->left);
        if(leftmax==-1) return -1;
        int rightmax=check(root->right);
        if(rightmax==-1) return -1;
        if(abs(rightmax-leftmax)>1) return -1;
        return 1+max(leftmax,rightmax);
    }
    bool isBalanced(TreeNode* root) {
        return check(root)!=-1;
    }
};