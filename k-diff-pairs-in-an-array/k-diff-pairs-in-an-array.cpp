class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int,int>ans;
        int count=0;
        for(int i: nums)
            ans[i]++;
        
        for(auto it=ans.begin(); it!=ans.end();it++)
        {
            if(k>0)
            {
                if(ans.find(it->first + k)!=ans.end())
                    count++;
            }
            
            else if(k==0)
                if(it->second>1)
                    count++;
        }
        return count;
        
    }
};