class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
        int n=nums.size();
        if(n<3)
            return {};
        
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        
        for(int i=n-1;i>=2;i--)
        {
            if(nums[i]<0)
                break;
            
            if(i>=0 && i<=n-2 && nums[i]==nums[i+1])
               continue;
            
            int k=0;
            int j=i-1;
            int ele=-1*nums[i];
            
            while(k<j)
            {
                if(nums[k]+nums[j]==ele)
                {
                    ans.push_back({nums[i],nums[k],nums[j]});
                    int left=nums[k];
                    int right=nums[j];
                    
                    while(k<nums.size() && nums[k]==left)
                    k++;
                    
                    while(j>=0 && nums[j]==right)
                    j--;
                }
                
                else if(nums[k]+nums[j]<ele)
                    k++;
                
                else
                    j--;
            }
            
        }
        
        
        return ans;
        
    }
};