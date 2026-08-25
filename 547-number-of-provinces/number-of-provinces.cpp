class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,int i, int n, vector<int>& visited){
        visited[i]=1;
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && visited[j]==0){
                dfs(isConnected,j,n,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,0);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(isConnected,i,n,visited);
                provinces++;
            }
        }
        return provinces;
    }
};