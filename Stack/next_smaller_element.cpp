vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int>stk;
    int n = A.size();
    vector<int>nse(n,-1);
    for(int i=0;i<n;i++){
        while(!stk.empty()&&stk.top()>=A[i]){
            stk.pop();
        }
        if(!stk.empty()) nse[i]=stk.top();
        stk.push(A[i]);
    }
    return nse;
}