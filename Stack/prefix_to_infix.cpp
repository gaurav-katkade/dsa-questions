//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string>stk;
        for(int i=pre_exp.length()-1;i>=0;i--){
            char c = pre_exp[i]; 
            string s(1,c);
            if((c>='a'&&c<='z')||
               (c>='A'&&c<='Z')||
               (c>='0'&&c<='9')){
                stk.push(s);  
            }else{
                string a = stk.top();
                stk.pop();
                string b = stk.top();
                stk.pop();
                stk.push("("+a+s+b+")");
            }
        }
        string result = stk.top();
        stk.top();
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
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends