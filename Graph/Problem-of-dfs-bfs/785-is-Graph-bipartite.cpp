class Solution {
public:
    bool dfs(int node,int col,vector<vector<int>>&graph,int color[]){
        color[node] = col;
        cout<<"node"<<node<<"col"<<col;
        for(auto ele:graph[node]){
            //for unvisited
            if(color[ele]==-1){
                if(dfs(ele,!col,graph,color)==false){
                    return false;
                }
            }else if(color[ele]==col){
                //color[ele]=col if mistakly wrote this resulting in wastage of 1 hr
                //when same color
                cout<<"color[ele]"<<color[ele]<<ele<<node;
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int color[V];
        for(int i=0;i<V;i++)color[i]=-1;
        // to check for components
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};