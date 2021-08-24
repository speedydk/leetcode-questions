class Solution {
public:
    
    int numRollsToTarget(int d, int f, int target) {
        int mod= 1e9+7;
        vector<vector<int>>dp(d+1,vector<int>(1001,0));
        for(int i=1; i<=f; i++)
            dp[1][i]=1;
        
        for(int i=2; i<=d; i++)
        {
            for(int j=1; j<=target; j++)
            {
                int sum=0;
                for(int k=1; k<=f; k++)
                {
                    if(j-k<0)
                        break;
                    sum = (sum + dp[i-1][j - k])%mod;
                }
                
                dp[i][j] = sum;
            }
        }
       return dp[d][target];
    }
};