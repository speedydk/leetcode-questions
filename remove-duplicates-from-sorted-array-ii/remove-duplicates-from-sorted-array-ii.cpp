class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int ptr=0;
        
        for(int i=0;i<nums.size();i++)
        {
            int j=i;
            int count=0;
            while(j<nums.size() && nums[j]==nums[i])
            {
                j++;
                count++;
            }
            
            count= min(2,count);
            while(count)
            {
                nums[ptr]=nums[i];
                ptr++;
                i++;
                count--;
            }
                
            i=j-1;
        }
        return ptr;
    }
};