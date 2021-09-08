class Solution {
public:
    
    int partition(vector<int>&nums, int start, int end)
    {
        int pivot= nums[end];
        int i= start-1;
        
        for(int j=start; j<end; j++)
        {
            if(nums[j]>= pivot)
            {
                i= i+1;
                swap(nums[i], nums[j]);
            }
        }
            
            swap(nums[i+1], nums[end]);
            return i+1;
    }
    
    int quickselect(vector<int>& nums, int start, int end, int k)
    {
        int pi= partition(nums, start, end);
        
        if(k>pi)
            return quickselect(nums, pi+1, end, k);
        
        else if(k<pi)
            return quickselect(nums, start, pi-1, k);
        
        else
            return nums[pi];
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size()-1, k-1);
    }
};