//Optimal - Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int el;
        for(int i=0;i<n;i++){
            if(cnt == 0){
                el = nums[i];
                cnt++;
            }else if(el == nums[i]){
                cnt++;
            }else{
                cnt--;
            }
        }
        return el;
    }
};

//Better
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        //TC- O(NlogN) + O(n)
        //SC - O
        unordered_map<int,int>mmap(n);
        for(int i=0;i<n;i++){
            mmap[nums[i]]++;
        }
        for(auto it :mmap){
            if(it.second > n/2){
                return it.first;
            }
        }
        return 0;
    }
};