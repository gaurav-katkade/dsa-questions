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

//Better Approch
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 1;
        int n = nums.size();
        if(n==0) return 0;
        int seq = 1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                cnt++;
            }else if(nums[i]!=nums[i-1]){
                cnt = 1;
            }
            seq = max(seq,cnt);
        }
        return seq;
    }
};

// TC - O(N) + O(N^2)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int seq = 1;

        unordered_set<int>sset(nums.begin(),nums.end());
        for(auto it:sset){
            if(sset.find(it-1)!= sset.end()){
                auto temp = it;int cnt = 0;
                while(sset.find(temp -1)!=sset.end()){
                    temp = temp + 1;
                    cnt ++;
                }
                seq = max(cnt,seq);
            }
        }
        return seq;
    }
};