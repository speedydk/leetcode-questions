class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long int>dp(target+1,0);
        int size= nums.size();
        int k=0;
        sort(nums.begin(), nums.end());
        while(k<size && nums[k]<=target)
        {
            dp[nums[k]]=1;
            k++;
        }
        
        for(int i=1; i<=target; i++)
        {
            int k=0;
            int sum= 0;
            while(k<size && nums[k]<=i)
                sum = sum + dp[i-nums[k++]];
            dp[i]=dp[i] + sum;
        }
        return dp[target];
    }
};