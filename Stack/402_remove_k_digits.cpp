class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(n == k){
            return "0";
        }
        stack<int>stk;
        for(int i=0;i<n;i++){
            while(!stk.empty()&&k>0&&stk.top()>num[i]){
                stk.pop();
                k--;
            }
            if(!(stk.empty()&&num[i]=='0')){
                stk.push(num[i]);
            }
        }
        while(!stk.empty()&&k>0){
            stk.pop();
            k--;
        }
        string ans(stk.size(),-1);
        for(int i=stk.size()-1;i>=0;i--){
            ans[i]=stk.top();
            stk.pop();
        }
        if(ans.size()==0)
            ans.push_back('0');
        return ans;
    }
};