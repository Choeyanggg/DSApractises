class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int count=0;
        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int size=q.size();
            count++;
            while(size--){
                auto[r,c]=q.front();
                q.pop();
                for(auto dir:directions){
                    int nr=r+dir[0];
                    int nc=c+dir[1];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }return count==0?0:count-1;
    }
};