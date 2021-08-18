class Solution {
public:
    
    void cal(vector<vector<int>>&ans, vector<int>contri, vector<int>&nums, int i, int size)
    {
        //base condition
        if(i==size)
        {
            ans.push_back(contri);
            return;
        }
        
        contri.push_back(nums[i]);
        cal(ans,contri,nums,i+1,size);
        int j=i;
        while(j+1<size && nums[i]==nums[j+1])
            j++;
        contri.pop_back();
        cal(ans,contri,nums,j+1,size);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>contri;
        sort(nums.begin(),nums.end());
        int size= nums.size();
        cal(ans,contri,nums,0,size);
        return ans;
        
    }
};