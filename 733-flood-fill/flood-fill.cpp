class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c,int original,int color,vector<vector<int>> &directions){
        image[r][c]=color;
        for(auto dir:directions){
            int nr=r+dir[0];
            int nc=c+dir[1];
            if(nr>=0 && nr<image.size() && nc>=0 && nc<image[0].size()){
                if(image[nr][nc]==original){
                    dfs(image,nr,nc,original,color,directions);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        int original=image[sr][sc];
        if(original==color) return image;
        dfs(image,sr,sc,original,color,directions);
        return image;
    }
};