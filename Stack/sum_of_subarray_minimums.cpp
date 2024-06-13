class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long ans =0;
        int n = arr.size();
        stack<pair<int,int>>sleft,sright;
        vector<int>left(n);
        vector<int>right(n);
        for(int i=0;i<n;i++){
            int cnt = 1;
            while(!sleft.empty()&&sleft.top().first>arr[i]){
                cnt+=sleft.top().second;
                sleft.pop();
            }
            sleft.push({arr[i],cnt});
            left[i] = cnt;
        }
        for(int i=n-1;i>=0;i--){
            int cnt = 1;
            while(!sright.empty()&&sright.top().first>=arr[i]){
                cnt+= sright.top().second;
                sright.pop();
            }
            sright.push({arr[i],cnt});
            right[i]= cnt;
        }
        int mod = 1e9+7;
        for(int i=0;i<n;i++){
            ans += (long long)arr[i]*(long long)left[i]*right[i]*1LL;
            ans %= mod;
            
        }
        return (int)ans;
    }
};