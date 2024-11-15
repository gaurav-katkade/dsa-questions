//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=0,j=0;
    	int maxcnt = 0;
    	int cnt = 0;
    	while(i<n && j<n){
    	    if(arr[i]<=dep[j]){
    	        cnt++;
    	        i++;
    	    }else{
    	        cnt--;
    	        j++;
    	    }
    	    maxcnt = max(maxcnt,cnt);
    	}
    	return maxcnt;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends


//Better approach
//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        vector<pair<int,char>>drr;
        int n = arr.size();
        for(int i=0;i<n;i++){
            drr.push_back({arr[i],'A'});
        }
        for(int i=0;i<n;i++){
            drr.push_back({dep[i],'D'});
        }
        int ans = 0;
        int cnt = 0;
        sort(drr.begin(),drr.end());
        for(int i=0;i<2*n;i++){
            if(drr[i].second=='A'){
                cnt++;
            }else{
                cnt--;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
//  Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> dep(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++) {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep) << endl;
    }
    return 0;
}
// } Driver Code Ends