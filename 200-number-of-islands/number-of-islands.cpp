class Solution {
public:
    bool dfs(vector<vector<char>>& grid,vector<vector<int>>& directions,vector<vector<int>>& visited, int r, int c){
        int n=grid.size();
        int m=grid[0].size();
        visited[r][c]=1;
        bool isclosed=true;
        for(auto dir:directions){
            int nr=r+dir[0];
            int nc=c+dir[1];
            if(nr>=0 && nr<n && nc>=0 && nc<m && 
            grid[nr][nc]=='1' && visited[nr][nc]==0){
                if(!dfs(grid,directions,visited,nr,nc)){
                    isclosed=false;
                }
            }
        }
        return isclosed;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    if(dfs(grid,directions,visited,i,j)){
                        count++;
                    }
                }
            }
        }return count;
    }
};