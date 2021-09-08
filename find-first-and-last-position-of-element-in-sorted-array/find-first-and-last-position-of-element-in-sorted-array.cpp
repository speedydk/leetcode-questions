class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return {-1,-1};
        vector<int>ans={-1,-1};
        int low=0, high=nums.size()-1, mid;
        while(low<high)
        {
            mid= low + (high-low)/2;
            
            if(nums[mid]<target)
                low= mid+1;
            
            else
                high= mid;
        }
        
        if(nums[low]==target)
            ans[0]=low;
        else return ans;
        
        low=0, high= nums.size()-1;
        
        while(low<high)
        {
            mid= low + (high-low+1)/2;
            
            if(nums[mid]<=target)
                low= mid;
            
            else
                high= mid-1;
        }
           ans[1]=low;
        
        return ans;
    }
};