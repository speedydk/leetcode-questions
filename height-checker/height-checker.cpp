class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        map<int,int>height;
        
        int count=0;
        
        for(auto it: heights)
            height[it]++;
        
        int i=0;
        
        for(auto it=height.begin(); it!=height.end(); it++)
        {
            while(it->second!=0)
            {
                if(it->first!=heights[i])
                    count++;
                
                it->second--;
                i++;
            }
        }
        
        return count;
    }
};