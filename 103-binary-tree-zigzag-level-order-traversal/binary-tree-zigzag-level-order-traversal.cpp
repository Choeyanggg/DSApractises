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
    void bfs(TreeNode* root, vector<vector<int>> &res){
        if (!root) return ;
        queue<TreeNode*> q;
        q.push(root);
        int c=0;
        while(!q.empty()){
            int size=q.size();
            vector<int> curr;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                curr.push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(c%2!=0) reverse(curr.begin(),curr.end());
            c++;
            res.push_back(curr);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bfs(root,res);
        return res;
    }
};