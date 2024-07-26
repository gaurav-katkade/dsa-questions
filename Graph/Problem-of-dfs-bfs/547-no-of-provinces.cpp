class Solution {
public:
    void dfsfun(int node,vector<bool>&visited,vector<vector<int>>& isConnected,int n){
        visited[node] = true;
        for(int i=0;i<n;i++){
            if(!visited[i] && isConnected[node][i]==1){
                dfsfun(i,visited,isConnected,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();// n: no of vertices
        vector<bool>visited(n,false);
        int num = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                num++;
                dfsfun(i,visited,isConnected,n); 
            }
        }
        return num;
    }
};