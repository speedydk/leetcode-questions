class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
        int max_sum= nums[0];
        int result=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            max_sum= max(max_sum+nums[i], nums[i]);
            result= max(result,max_sum);
        }
        
        return result;
        
    }
};