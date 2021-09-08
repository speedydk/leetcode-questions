class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0, high= nums.size()-1, mid;
        int size= nums.size();
        
        if(size==1)
            return 0;
        
        else if(size==2)
            return (nums[0]<nums[1]?1:0);
            
        while(low<=high)
        {
            mid= low + (high-low)/2;
            
            if((mid==0 && mid+1<size && nums[mid]>nums[mid+1]) || (mid-1>=0 && mid==size-1 && nums[mid-1]<nums[mid]) || (mid>0 && mid<size-1 && nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]))
                return mid;
            
            else if(mid+1<size && nums[mid]<nums[mid+1])
                low= mid+1;
            
            else
                high= mid;
        }
        return mid;
    }
};