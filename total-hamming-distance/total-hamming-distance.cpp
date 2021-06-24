class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        int count=0;
        for(int i=0;i<32;i++)
        {
            int zero=0;
            int one=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j] & (1<<i))
                    one++;
                
                else
                    zero++;
            }
            
            count+=one*zero;
            
        }
        
        return count;
        
    }
};