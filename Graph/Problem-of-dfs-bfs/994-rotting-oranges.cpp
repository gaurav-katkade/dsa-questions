class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        // {{r,c},t}
        queue<pair<pair<int,int>,int>>q;

        //for finding rotton oranges and storing it into queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }else{
                    vis[i][j] = 0;
                }
            }
        }
        //until we visit all possible nodes
        int tm = 0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = t;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = drow[i] + r;
                int ncol = dcol[i] + c;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]!=1){
                    return -1;
                }
            }
        }
        return tm;
    }
};