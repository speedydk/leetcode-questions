class Solution {
public:
    
    int find_index(vector<int>& nums)
    {
        int size= nums.size()-1;
        
        for(int i=size; i>0; i--)
        {
            if(nums[i]>nums[i-1])
                return i-1;
        }
        
        return -1; 
    }
    
    
    int find_next_num(int index, vector<int>&nums)
    {
        int l= index + 1;
        int r= nums.size() - 1;
        
        int mid;
        while(l<r)
        {
            mid= l + (r-l+1)/2;
            if(nums[mid]>nums[index])
                l= mid;
            
            else
                r=mid-1;
        }
        return l;
    }
    
    void nextPermutation(vector<int>& nums) {
        
        
        //find the element not following the descending order
        //find the element greater than that element on right side, swap the elements 
        //reverse the element on the right side
        
        int index= find_index(nums);
        
        if(index==-1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int k= find_next_num(index, nums);
        cout<<index<<" "<<k;
        swap(nums[index],nums[k]);
        
        reverse(nums.begin()+index+1, nums.end());
    }
};