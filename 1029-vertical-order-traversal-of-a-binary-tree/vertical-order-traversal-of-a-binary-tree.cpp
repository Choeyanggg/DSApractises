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
    vector<tuple<int,int,int>> cor;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(root,0,0);
        sort(cor.begin(),cor.end());
        int prev_col=INT_MIN;
        for(auto [col,row,val]:cor){
            if(col==prev_col){
                curr.push_back(val);
            }else{
                if(!curr.empty()){
                    res.push_back(curr);
                }
                curr.clear();
                curr.push_back(val);
                prev_col=col;
            }
        }
        if(!curr.empty()){
            res.push_back(curr);
        }
        return res;
    }
    void dfs(TreeNode* root, int row,int col){
        if(!root) return ;
        cor.push_back({col,row,root->val});
        dfs(root->left,row+1,col-1);
        dfs(root->right,row+1,col+1);
    }
};