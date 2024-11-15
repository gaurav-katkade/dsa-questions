//Apna Apna Logic
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int n = nums.size();
        // 1000
        int prev;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i+1] = 1000;
                prev = nums[i];
            }else if(nums[i]==1000){
                if(nums[i+1]==prev){
                    nums[i+1] = 1000;
                }
            }
        }
        sort(nums.begin(),nums.end());
        i = 0;
        while(i<n && nums[i]!=1000){
            i++;
        }
        return i;
    }
};

//Brute Force
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>sset;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sset.insert(nums[i]);
        }
        int k = sset.size();
        int i = 0;
        for(auto it:sset){
            nums[i] = it;
            i++;
        }
        return k;
    }
};

//Optimal

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0;
        int n = nums.size();
        for(int j=0;j<n;j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};