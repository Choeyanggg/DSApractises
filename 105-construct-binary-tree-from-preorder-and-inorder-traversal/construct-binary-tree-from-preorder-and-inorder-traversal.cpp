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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> in_mp;
        for(int i=0;i<inorder.size();i++){
            in_mp[inorder[i]]=i;
        }
        TreeNode* root=helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1, in_mp);
        return root;
    }
    TreeNode* helper(vector<int> &preorder,int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int,int> &mp){
        if(preStart>preEnd || inStart>inEnd) return nullptr;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inRoot=mp[root->val];
        int inLeft=inRoot-inStart;
        root->left=helper(preorder,preStart+1,preStart+inLeft,inorder,inStart,inRoot-1,mp);
        root->right=helper(preorder,preStart+inLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);
        return root;
    }
};