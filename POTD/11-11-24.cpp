//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Code here
        int n = arr.size();
        int total_cnt = 0;
        unordered_map<int,int>mpp;//val,count
        unordered_set<int> sset(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
            if(mpp[arr[i]]>1){
                int cnt =0;
                while(sset.find(arr[i])!=sset.end()){
                    arr[i]+=1;
                    cnt+=1;  
                }
                sset.insert(arr[i]);
                total_cnt+=cnt;
                
            }
        }
        return total_cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends