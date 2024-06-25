//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Meeting{
    int start;
    int end;
    // int pos;
};
bool comp(Meeting a,Meeting b){
    return a.end < b.end;
}
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        Meeting arr[n];
        for(int i=0;i<n;i++){
            arr[i].start = start[i];
            arr[i].end = end[i];
        }
        sort(arr,arr+n,comp);
        int freetime = -1;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(freetime<arr[i].start){
                cnt++;
                freetime = arr[i].end;
            }
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends