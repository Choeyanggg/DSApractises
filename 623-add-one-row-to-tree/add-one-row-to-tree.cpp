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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        if(depth==1){
            TreeNode* oldroot=root;
            root=new TreeNode(val);
            root->left=oldroot;
        }
        q.push(root);
        int layer=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                TreeNode* node=q.front();
                q.pop();
                if(layer==depth-1){
                    TreeNode* left=node->left;
                    TreeNode* right=node->right;
                    node->left=new TreeNode(val);
                    node->right=new TreeNode(val);
                    node->left->left=left;
                    node->right->right=right;
                }else{
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }layer++;
        }return root;
    }
};