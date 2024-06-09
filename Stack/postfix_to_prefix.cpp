//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        stack<string>stk;
        for(int i=0;i<post_exp.length();i++){
            char c = post_exp[i];
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
               stk.push(s+s2+s1);
            }
        }
        string res = stk.top();
        stk.pop();
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends