class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    queue<pair<int,int>>q;
    int n = image.size();
    int m = image[0].size();
    int old_color = image[sr][sc];
    if(old_color == color) return image;
    q.push({sr,sc});
    image[sr][sc] = color;
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow  = drow[i] + r;
            int ncol = dcol[i] + c;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==old_color){
                q.push({nrow,ncol});
                image[nrow][ncol] = color;
            }
        }
    }
    return image;    
    }
    
};