class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a=0, b=nums.size()-1;
        
        while(a<b)
        {
            int sum= nums[a]+nums[b];
            
            //sum==target
            if(sum==target)
                return {a+1,b+1};
            
            else if(sum>target)
                b--;
            
            else
                a++;
        }
        return {};
    }
};