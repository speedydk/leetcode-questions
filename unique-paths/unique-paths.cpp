class Solution {
public:
    
    int count_path(int a, int b, int& m, int& n, vector<vector<int>>&dp)
    {
        //base condition
        if( a==m || b==n )
            return 0;
        
        if(a==m-1 && b==n-1)
            return 1;
        
        if(dp[a][b]!=-1)
            return dp[a][b];
        
        return dp[a][b]= count_path(a+1, b , m, n,dp) + count_path(a, b+1, m, n,dp);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return count_path(0,0, m, n,dp);
    }
};