class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i=0;
        int j=0;
        int sum=0;
        int mini_length=INT_MAX;
        
        for(int i=0; i<nums.size(); i++)
        {
            while(j<nums.size() && sum<target)
            {
                sum+= nums[j];
                j++;
            }
            
            if(sum<target)
                break;
            
            mini_length=min(mini_length, j-i);
            
            sum=sum-nums[i];            
        }
        return mini_length == INT_MAX ? 0 : mini_length;
    }
};