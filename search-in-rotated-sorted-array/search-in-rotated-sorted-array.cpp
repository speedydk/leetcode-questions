class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size()==1 && nums[0]==target)
            return 0;
        
        else if(nums.size()==1 && nums[0]!=target)
            return -1;
    
        
        int low=0, high= nums.size()-2, mid;
        int tar= nums[high+1];
        
        while(low<high)
        {
            mid= low + (high - low +1)/2;
            
            if(nums[mid]>tar)
                low= mid;
            
            else
                high= mid-1;
        }
        
        if(target==nums[low])
            return low;
        
        if(target<nums[low] && target>=nums[0])
        {
            high= low-1;
            low=0;
        }
        
        else
        {
            low++;
            high= nums.size()-1;
        }
            
        while(low<high)
        {
            mid= low + (high - low + 1)/2;
            
            if(nums[mid]<=target)
                low= mid;
            
            else
                high= mid-1;
        }
        
        if(nums[low]==target)
        return low;
        
        return -1;
    }
};