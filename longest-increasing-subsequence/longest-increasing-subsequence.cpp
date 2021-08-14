class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int size= nums.size();
        vector<int>dp(size,1);
        int count=1;
        
        for(int i=0; i<size; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j] && dp[i]<=dp[j])
                    count= max(count, ++dp[i]);
            }
        }
        
        return count;
        
    }
};