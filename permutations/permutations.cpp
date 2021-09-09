class Solution {
public:
    
    void order(vector<int>& nums, vector<vector<int>>& ans, int i)
    {
        //base condition
        if(i==nums.size()-1)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int j=i; j<nums.size(); j++)
        {
            swap(nums[i],nums[j]);
            order(nums, ans, i+1);
            swap(nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>contri;
        order(nums, ans, 0);
        return ans;
    }
};