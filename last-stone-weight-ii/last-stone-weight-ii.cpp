class Solution {
public:
    int lastStoneWeightII(vector<int>& arr) {
        int sum=0;
        int n= arr.size();
	    for(int i=0; i<n; i++)
	    sum+= arr[i];
	    
	    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
	    int mini_diff= INT_MAX;
	    
	    for(int i=0; i<n+1; i++)
	    {
	        for(int j=0; j<sum+1; j++)
	        {
	            if(j==0)
	            {
	                dp[i][j] = true;
	                continue;
	            }
	            
	            if(i==0)
	            continue;
	            
	            if(j>= arr[i-1])
	            dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
	            
	            else
	            dp[i][j] = dp[i-1][j];
	            
	            if(dp[i][j] == true)
	            {
	                int set1 = j;
	                int set2 = sum - j;
	                mini_diff = min(mini_diff, abs(set1-set2));;
	            }
	        }
	    }
	    
	    return mini_diff;
    }
};