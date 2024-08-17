// Optimal : Using Set

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int ans = 0;
        unordered_set<int>st(nums.begin(),nums.end());
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt = 0;
                int x = it;
                while(st.find(x)!=st.end()){
                    cnt++;
                    x = x+1;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};