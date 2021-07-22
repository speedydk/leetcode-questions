class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>ans;
        int sum=0;
        ans[0]=1;
        int count=0;
        
        for(int i=1; i<nums.size(); i++)
           nums[i]=nums[i]+nums[i-1];
        
        for(int i=0; i<nums.size(); i++)
        {
            if(ans.find(nums[i]-k)!=ans.end())
                count+=ans[nums[i]-k];
            
            ans[nums[i]]++;
        }
        
        return count;
    }
};