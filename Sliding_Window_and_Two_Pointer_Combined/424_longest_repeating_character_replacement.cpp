//better
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int hash[26]={0};
        int left=0,right=0,maxlen=0,maxf=0;
        while(right<n){
            hash[s[right]-'A']++;
            maxf = max(maxf,hash[s[right]-'A']);
            while((right-left+1-maxf)>k){
                hash[s[left]-'A']--;
                for(int i=0;i<26;i++){
                    maxf = max(maxf,hash[i]);
                }
                left++;
            }
            maxlen = max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};

//more optimized 
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int hash[26]={0};
        int left=0,right=0,maxlen=0,maxf=0;
        while(right<n){
            hash[s[right]-'A']++;
            maxf = max(maxf,hash[s[right]-'A']);
            while((right-left+1-maxf)>k){
                hash[s[left]-'A']--;
                left++;
            }
            maxlen = max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};