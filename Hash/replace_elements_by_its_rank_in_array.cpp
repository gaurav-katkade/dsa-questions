//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<N;i++){
            pq.push(arr[i]);
        }
        int i = 1;
        while(!pq.empty() && i<=N){
            int top = pq.top();
            pq.pop();
            //we need to increment i for first time only
            if(mp.find(top)==mp.end()){mp[top]=i;
            i++;}
        }
        for(int i=0;i<N;i++){
            int val = mp[arr[i]];
            ans.push_back(val);
        }
        return ans;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends