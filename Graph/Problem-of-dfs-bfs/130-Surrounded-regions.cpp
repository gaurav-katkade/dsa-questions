class Solution {
public:
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<char>>& vis){
        vis[row][col]='O';
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' &&vis[nrow][ncol]=='X'){
                dfs(nrow,ncol,board,vis);
            }
        }
    }
    // to simplify the logic we use X->Not visited O->visited(rahter than 0,1)
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<char>>vis(n,vector(m,'X'));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(board[i][j]=='O' && vis[i][j]=='X')
                        dfs(i,j,board,vis);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j] = vis[i][j];
            }
        }
    }
};