class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX, sum=0, j=0;
        int n= nums.size();
        
        for(int i=0; i<n; i++)
        {
            while(j<n && sum<target)
            {
                sum+=nums[j];
                j++;
            }
            
            if(sum<target)
                break;
            
            ans= min(ans,j-i);
            sum-=nums[i];
        }
        
        return ans==INT_MAX?0:ans;
    }
};