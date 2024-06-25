class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>counter(3,0);
        // 0->5,1->10,2->20
        for(int i=0;i<bills.size();i++){
            if(bills[i]==10){    
                if(counter[0]>0){
                    counter[1]++;
                    counter[0]--;}
                else{return false;}
            }
            else if(bills[i]==20){
                if(counter[0]>0 && counter[1]>0){
                    counter[1]--;
                    counter[0]--;
                }else if(counter[0]>=3){
                    counter[0] -= 3;
                }else{
                    return false;
                }
            }else if(bills[i]==5){
                counter[0]++;
            }
        }
        return true;
    }
};