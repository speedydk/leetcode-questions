class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int count = 0;
        int size = nums.size();
        
        for(int i=0; i<size; i++)
        {
            if(count == 0)
            {
                ele = nums[i];
                count++;
            }
            
            else if(ele == nums[i])
                count++;
            
            else
                count--;
        }
        return ele;
    }
};