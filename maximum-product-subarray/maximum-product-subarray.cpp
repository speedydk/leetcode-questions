class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        int max_pro= nums[0], min_pro=nums[0], res=nums[0];
        
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]<0)
                swap(min_pro,max_pro);
            
            max_pro= max(max_pro*nums[i], nums[i]);
            min_pro= min(min_pro*nums[i], nums[i]);
            
            res= max(res, max_pro);
        }   
        
        return res;
    }
};