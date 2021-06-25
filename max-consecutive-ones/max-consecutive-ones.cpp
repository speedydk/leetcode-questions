class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            int count=0;
            int j=i;
            
            while(j<nums.size() && nums[i]==nums[j] && nums[i]==1)
            {
                count++;
                j++;
            }
            
            max_count= max( max_count, count);
            if(count)
                i=j-1;
        }
        
        return max_count;
    }
};