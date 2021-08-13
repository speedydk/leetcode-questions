class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0)s.push(i);
            else {
                while(!s.empty() && asteroids[s.top()]<abs(asteroids[i])){
                    asteroids[s.top()]=0;
                    s.pop();
                }
                if(!s.empty())
                    if(asteroids[s.top()]>abs(asteroids[i]))asteroids[i]=0;
                    else {
                        asteroids[i]=0;
                        asteroids[s.top()]=0;
                        s.pop();
                    }
            }
        }
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++)if(asteroids[i])ans.push_back(asteroids[i]);
        return ans;
    }
};