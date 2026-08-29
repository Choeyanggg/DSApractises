class Solution {
public:
    bool dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,vector<vector<int>>& directions, int r,int c,int n,int m){
        visited[r][c]=1;
        bool isClosed=true;

        if(r==0 || r==n-1 || c==0|| c==m-1) isClosed=false;

        for(auto dir:directions){
            int nr=r+dir[0];
            int nc=c+dir[1];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && visited[nr][nc]==0){
                if(!dfs(grid,visited,directions,nr,nc,n,m)){
                    isClosed=false;
                }
            }
        }
        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && visited[i][j]==0){
                    if(dfs(grid,visited,directions,i,j,n,m)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};