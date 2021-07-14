class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        int max_size = 0;
        for(int i = 0; i<=n; i++)
        {
            for(int j = 0; j<=m; j++)
            {
                if( i==0 || j==0 )
                continue;
                
                if( nums1[i-1] == nums2[j-1] )
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    max_size = max(max_size, dp[i][j]);
                }
            }
        }
        return max_size;
    }
};