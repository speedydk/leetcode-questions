class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        unordered_map<int,pair<int,int>>res;
        int n= nums.size();
        int degree=0;
        
        for(int i=0; i<n; i++)
        {
            if(res[nums[i]].first==0)
                res[nums[i]].second=i;
            
            res[nums[i]].first++;
            degree=max(degree,res[nums[i]].first);
        }
        
        int min_len=n;
        for(int i=n-1; i>=0; i--)
        {
            if(res[nums[i]].first==degree)
            {
                min_len= min(min_len, i-res[nums[i]].second+1);
                res[nums[i]].first=-1;
            }    
        }

        return min_len;
    }
};