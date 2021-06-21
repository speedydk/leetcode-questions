class Solution {
public:
    
    int lcs(string &s,string &r, vector<vector<int>>& dp, int i,int j)
    {
        //base condition
        if(i==0 || j==0)
            return 0;
        
        else if(dp[i-1][j-1]!=-1)
            return dp[i-1][j-1];
        
        else if(s[i-1]==r[j-1])
            return dp[i-1][j-1]=1+lcs(s,r,dp,i-1,j-1);

        return dp[i-1][j-1]=max(lcs(s,r,dp,i-1,j),lcs(s,r,dp,i,j-1));
    }
    
    int minInsertions(string s) {
        
        string r=s;
        reverse(r.begin(),r.end());
        
        vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,-1));
        int i=s.length();
        int j=r.length();
        int count=lcs(s,r,dp,i,j);
        //cout<<count;
        
        return i-count;
    }
        
};