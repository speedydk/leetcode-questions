class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int size = nums.size();
        int pre[size], suf[size];
        pre[0] = nums[0], suf[size-1] = nums[size-1];
        
        for(int i=1; i<size-1; i++)
        {
            pre[i]= min(pre[i-1], nums[i-1]);
            suf[size-i-1] = max(suf[size-i], nums[size-i]);
        }
        
        for(int i=1; i<size-1; i++)
        {
            if(pre[i]<nums[i] && suf[i]>nums[i])
                return true;
        }
        return false;
    }
};