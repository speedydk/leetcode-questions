class Solution {
public:
    
    int func(int n)
    {
        for(int i= 2; i<=sqrt(n) + 1; i++)
            if(n%i==0)
                return max(i,n/i);
        return -1;
    }
    
    
    int minSteps(int n) {
        vector<int>dp(n+1,0);
    
        for(int i=2; i<=n; i++)
        {
            if(i%2==0)
            {
                dp[i] = 2 + dp[i/2];
                continue;
            }
            
            int k= func(i);
            dp[i] = ((k==-1) ? i : dp[k] + 1 + (i/k-1));
        }
        return dp[n];
    }
};