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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=helper(preorder,0,preorder.size()-1);
        return root;
    }
    TreeNode* helper(vector<int> &preorder,int start, int end){
        if(start>end) return nullptr;
        TreeNode* root=new TreeNode(preorder[start]);
        int split=start+1;
        while(split<=end && preorder[split]<root->val){
            split++;
        }
        root->left=helper(preorder,start+1,split-1);
        root->right=helper(preorder,split,end);
        return root;
    }
};