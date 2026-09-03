class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            ans=max(ans,t);
            if(r-1>=0 && grid[r-1][c]==1 && visited[r-1][c]==0){
                q.push({{r-1,c},t+1});
                visited[r-1][c]=1;
            }
            if(r+1<n && grid[r+1][c]==1 && visited[r+1][c]==0){
                q.push({{r+1,c},t+1});
                visited[r+1][c]=1;
            }
            if(c-1>=0 && grid[r][c-1]==1 && visited[r][c-1]==0){
                q.push({{r,c-1},t+1});
                visited[r][c-1]=1;
            }
            if(c+1<m && grid[r][c+1]==1 && visited[r][c+1]==0){
                q.push({{r,c+1},t+1});
                visited[r][c+1]=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    return -1;
                }
            }
        }return ans;
    }
};