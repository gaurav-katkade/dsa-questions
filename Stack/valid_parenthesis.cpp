class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                stk.push(s[i]);
            }else{
                if(stk.empty()){
                    return false;
                }else{
                    char y = stk.top();
                    
                    if((s[i]=='}'&& y == '{') ||
                       (s[i]==']'&& y == '[') ||
                       (s[i]==')'&& y == '(')){
                        stk.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        if(stk.empty()){
            return true;
        }
        return false;
    }
};