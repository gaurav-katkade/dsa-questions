//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char c){
        if(c=='+'||c=='-') return 1;
        else if(c=='*'||c=='/')return 2;
        else if(c=='^')return 3;
        else return -1;
        
    }
    string infixToPostfix(string s) {
        string result;
        stack<char>stk;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if((c>='a'&&c<='z')||
               (c>='A'&&c<='Z')||
               (c >=0 &&c <= 9)){
                   result+=c;
               }
            else if(c=='('){
                stk.push(c);
            }
            else if(c==')'){
                while(!stk.empty()&&stk.top()!='('){
                    result+=stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else{
                //operator
                while(!stk.empty()&&prec(c)<=prec(stk.top())){
                    result+=stk.top();
                    stk.pop();
                }
                stk.push(c);
            }
        }
        while(!stk.empty()){
            result+=stk.top();
            stk.pop();
        }
        return result;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends