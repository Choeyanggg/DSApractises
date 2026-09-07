class Solution {
public:
    void island(int &area,vector<vector<int>>& grid,int r, int c){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0) return;
        grid[r][c]=0;
        area+=1;

        island(area,grid,r-1,c);
        island(area,grid,r+1,c);
        island(area,grid,r,c-1);
        island(area,grid,r,c+1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int area=0;
                    island(area,grid,i,j);
                    maxarea=max(maxarea,area);
                }
            }
        }return maxarea;
    }
};