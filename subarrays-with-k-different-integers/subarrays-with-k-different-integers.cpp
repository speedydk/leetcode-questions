class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return Helper(nums,k)-Helper(nums,k-1);
        
    }
    
    int Helper(vector<int>& nums, int k)
    {
        unordered_map<int, int>count;
        int j=0;
        int maxi=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(!count[nums[i]]++)
                k--;
            
            while(k<0)
            {
                if(!--count[nums[j]])
                    k++;
                j++;
            }
            
            maxi = maxi + i-j+1;
            
        }
        
        return maxi;
        
    }
};