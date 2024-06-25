class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26);
        for(auto ch:tasks){
            freq[ch-'A']++;
        }
        //sorting so max frq come first
        sort(freq.begin(),freq.end(),greater<int>());
        //calculating idle count
        int ideal = (freq[0]-1)*n;
        for(int i=1;i<freq.size();i++){
            ideal = ideal - min(freq[0]-1,freq[i]);
        }
        return tasks.size()+max(0,ideal);
    }
};