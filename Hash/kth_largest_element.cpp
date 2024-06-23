//logic 1 : simple logic
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        for(int i=0;i<k;i++){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};
//logic 2 : using min Heap single loop
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size=nums.size();
        priority_queue<int,vector<int>,greater<int>> minheap;
        for(int i=0;i<size;i++)
        {
            minheap.push(nums[i]);
            if(minheap.size()>k)
            {
                minheap.pop();
            }
        }
        return minheap.top();
    }
};