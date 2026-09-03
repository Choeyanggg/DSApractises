class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>res(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    res[i][j]=0;
                }
            }
        }
        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(auto dir: directions){
                int nr=r+dir[0];
                int nc=c+dir[1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && res[nr][nc]==-1){
                    res[nr][nc]=res[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return res;
    }
};