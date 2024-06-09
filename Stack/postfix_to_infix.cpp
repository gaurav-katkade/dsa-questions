//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string>stk;
        for(int i=0;i<exp.length();i++){
            string s(1,exp[i]);
            if((s>="A"&&s<="Z")||
               (s>="a"&&s<="z")||
               (s>="0"&&s<="9")){
                   stk.push(s);
            }else{
                string s1 = stk.top();
                stk.pop();
                string s2 = stk.top();
                stk.pop();
                stk.push("("+s2+s+s1+")");
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
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends