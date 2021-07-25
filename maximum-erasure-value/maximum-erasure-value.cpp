class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int ans=0, n=nums.size(), j=0;
        unordered_map<int,int>fre;
        int temp_sum= 0;
        
        for(int i=0; i<n; i++)
        {
            while(j<n && fre[nums[j]]==0)
            {
                temp_sum+= nums[j];
                fre[nums[j]]++;
                j++;
            }
            
            ans= max(ans,temp_sum);
            if(j==n)
                return ans;
            temp_sum-=nums[i];
            fre[nums[i]]--;
        }
        return ans;
    }
};