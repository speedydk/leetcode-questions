class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int size = nums.size();
        int good_num = size-1;
        for(int i=size-2; i>=0; i--)
        {
            if(nums[i] + i >= good_num)
                good_num = i;
        }
        return good_num == 0;
    }
};