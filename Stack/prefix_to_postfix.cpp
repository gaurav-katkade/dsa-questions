//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string>stk;
        for(int i=pre_exp.length()-1;i>=0;i--){
            char c = pre_exp[i];
            string s(1,c);
            if((c>='a'&&c<='z')||
               (c>='A'&&c<='Z')||
               (c>='0'&&c<='9')){
                stk.push(s); 
            }else{
                string s1 = stk.top();
                stk.pop();
                string s2 = stk.top();
                stk.pop();
                stk.push(s1+s2+s);
            }
        }
        string result = stk.top();
        stk.pop();
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends