class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=INT_MIN;
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int count=0;
                    visited[i][j]=1;
                    q.push({i,j});
                    while(!q.empty()){
                        auto[r,c]=q.front();
                        q.pop();
                        count++;
                        for(auto dir:directions){
                            int nr=r+dir[0];
                            int nc=c+dir[1];
                            if(nr>=0 && nr<n && nc>=0 && nc<m){
                                if(grid[nr][nc]==1 && !visited[nr][nc]){
                                    q.push({nr,nc});
                                    visited[nr][nc]=1;
                                }
                            }
                        }
                    }maxi=max(maxi,count);
                }
            }
        }return maxi==INT_MIN?0:maxi;
    }
};