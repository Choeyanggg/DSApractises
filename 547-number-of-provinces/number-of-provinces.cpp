class Solution {
public:
    void dfs(int i, vector<vector<int>>& isConnected, vector<int>& visited){
        visited[i]=1;
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[i][j]==1 && visited[j]==0){
                dfs(j,isConnected,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> res(n,0);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(res[i]==0){
                dfs(i,isConnected,res);
                provinces++;
            }
        }
        return provinces;
    }
};