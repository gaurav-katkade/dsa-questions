class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>stk;
        stk.push(asteroids[0]);
        for(int i= 1;i<n;i++){
            if(asteroids[i]>0){
                stk.push(asteroids[i]);
            }else{
                while(!stk.empty()&&stk.top()>0&&stk.top()<abs(asteroids[i])){
                    stk.pop();
                }
                if(!stk.empty()&&stk.top()==abs(asteroids[i])){
                    stk.pop();
                }
                else if(stk.empty()||stk.top()<0){
                    stk.push(asteroids[i]);
                }
            }
        }
        vector<int>res(stk.size());
        for(int i = stk.size()-1;i>=0;i--){
            res[i]=stk.top();
            stk.pop();
        }
        return res;
    }
};