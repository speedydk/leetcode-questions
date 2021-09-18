class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n,nums[0]), suf(n,nums[n-1]);
        
        for(int i=1; i<n-1; i++)
        {
            pre[i] = pre[i-1] * nums[i];
            suf[n-i-1] = suf[n-i] * nums[n-i-1];
        }
        
        vector<int>ans(n);
        ans[n-1] = pre[n-2], ans[0] = suf[1];
        
        for(int i=1; i<n-1; i++)
            ans[i] = pre[i-1] * suf[i+1];
        return ans;
    }
};