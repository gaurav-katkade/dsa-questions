#include <iostream>
#include<unordered_map>
using namespace std;
//code to check two string are anagram or not
bool check_anagram(string s1,string s2){
    unordered_map<char,int>mpp;
    for(int i=0;i<s1.length();i++){
        mpp[s1[i]]++;   
    }
    for(int i=0;i<s2.length();i++){
        mpp[s2[i]]--;
    }
    for(auto& pair:mpp){
        if(pair.second!=0){
            return false;
        }
    }
    return true;
}
int main()
{
    
    cout<<check_anagram("twa","wat");
    return 0;
}