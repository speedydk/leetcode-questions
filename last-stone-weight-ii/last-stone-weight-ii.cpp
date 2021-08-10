class Solution {
public:
    int lastStoneWeightII(vector<int>& arr) {
        
        int size= arr.size();
        int sum=0;
        
        for(auto it: arr)
            sum+= it;
        
        vector<vector<bool>>dp(size+1,vector<bool>(sum/2+1,false));
        dp[0][0]= true;
        
        for(int i=1; i<=size; i++)
        {
            for(int j=0; j<=sum/2; j++)
            {
                if(j==0)
                    dp[i][j]= true;
                
                else if(arr[i-1]<=j)
                    dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
                
                else
                    dp[i][j]= dp[i-1][j];
            }
        }
        
        
        int ans= INT_MAX;
        for(int j=0; j<=sum/2; j++)
        {
            if(dp[size][j]==true)
                ans= min(ans,abs(sum-2*j));
        }
        
        return ans;
    }
};