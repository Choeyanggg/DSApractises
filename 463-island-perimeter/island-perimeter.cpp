class Solution {
public:
    int res=0;
    queue<pair<int,int>> q;
    void bfs(vector<vector<int>>& grid,int r, int c,vector<vector<int>> &direction, vector<vector<bool>> &visited){
        q.push({r,c});
        visited[r][c]=true;
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(auto dir:direction){
                int nr=r+dir[0];
                int nc=c+dir[1];
                if(nr<0 || nr>=grid.size() || 
                    nc<0 || nc>=grid[0].size() ||
                    grid[nr][nc]==0){
                    res++;
                }else if(!visited[nr][nc]){
                    visited[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> direction={
            {-1,0},{1,0},{0,-1},{0,1}
        };
        vector<vector<bool>> visited(
            grid.size(), vector<bool>(grid[0].size(),false)
        );
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    bfs(grid,i,j,direction,visited);
                }
            }
        }
        return res;
    }
};