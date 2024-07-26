//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectCycle(int root,int V,vector<int> adj[],int vis[]){
        queue<pair<int,int>>q;
        q.push({root,-1});
        vis[root] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto i:adj[node]){
                if(vis[i]==0){
                    q.push({i,node});
                    vis[i]=1;
                }
                else if(i!=parent){
                    return true;
                }
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        for(int i=0;i<V;i++){
           if(vis[i]==0){
               if(detectCycle(i,V,adj,vis)==true){
                   return true;
               }
           } 
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends