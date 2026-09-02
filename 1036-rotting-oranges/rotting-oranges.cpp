class Solution {
public:
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& directions, queue<pair<int,int>>& q){
        int n=grid.size();
        int m=grid[0].size();
        int min=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto[r,c]=q.front();
                q.pop();
                for(auto dir: directions){
                    int nr=r+dir[0];
                    int nc=c+dir[1];
                    if(nr<0 || nr>=n || nc<0 ||nc>=m) continue;
                    if(grid[nr][nc]==0) continue;
                    if(grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }
            }if(!q.empty())min+=1;
        }return min;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int count=bfs(grid,directions,q);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return count;
    }
};