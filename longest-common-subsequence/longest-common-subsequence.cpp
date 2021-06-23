class Solution {
public:
    
    int lcs(string &s,string &r, vector<vector<int>>& dp, int i,int j)
    {
        //base condition
        if(i==0 || j==0)
            return 0;
        
        else if(dp[i][j]!=-1)
            return dp[i][j];
        
        else if(s[i-1]==r[j-1])
            return dp[i][j]=1+lcs(s,r,dp,i-1,j-1);

        return dp[i][j]=max(lcs(s,r,dp,i-1,j),lcs(s,r,dp,i,j-1));
    }
    
    int longestCommonSubsequence(string s, string r) {
        int i=s.length();
        int j=r.length();
        // if(i<j)
        //     return longestCommonSubsequence(r,s);
        vector<vector<int>>dp(s.length()+1,vector<int>(r.length()+1,-1));
        return lcs(s,r,dp,i,j);
    }
};