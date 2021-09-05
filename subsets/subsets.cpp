class Solution {
public:
    
    void cal(vector<int>&nums, vector<vector<int>>&powe, vector<int>& contri, int i)
    {
        //base condition
        if(i==nums.size())
        {
            powe.push_back(contri);
            return;
        }
        
        cal(nums, powe, contri, i+1);
        contri.push_back(nums[i]);
        cal(nums, powe, contri, i+1);
        contri.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>powe;
        vector<int>contri;
        cal(nums, powe, contri, 0);
        return powe;
    }
};