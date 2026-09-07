class Solution {
public:
    bool check(vector<vector<char>>& board, int r,int c, vector<vector<bool>>& visited){
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size()) return false;
        if(board[r][c]=='X') return true;
        if(visited[r][c]) return true;
        visited[r][c]=true;

        bool up=check(board,r-1,c,visited);
        bool down=check(board,r+1,c,visited);
        bool left=check(board,r,c-1,visited);
        bool right=check(board,r,c+1,visited);
        return up && down && left && right;
    }
    void dfs(vector<vector<char>>& board,int r, int c){
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c]!='O') return;
        board[r][c]='X';

        dfs(board,r-1,c);
        dfs(board,r+1,c);
        dfs(board,r,c-1);
        dfs(board,r,c+1);
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    vector<vector<bool>> visited(n, vector<bool>(m,false));
                    if(check(board,i,j,visited)){
                        dfs(board,i,j);
                    }
                }
            }
        }
    }
};