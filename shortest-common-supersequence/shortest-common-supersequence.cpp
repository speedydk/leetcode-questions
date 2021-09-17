class Solution {
public:
    string shortestCommonSupersequence(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        string s="";
        int i = m, j = n;
    
        while(i>0 && j>0)
        {
            if(word1[i-1] == word2[j-1])
            {
                s=s+word1[i-1];
                i--;
                j--;
            }
            
            else
            {
                if(dp[i][j-1] > dp[i-1][j])
                {
                    s=s+word2[j-1];
                    j--;
                }
                
                else
                {
                    s=s+word1[i-1];
                    i--;
                }
            }
        }
    
        while(i>0)
        {
            s=s+word1[i-1];
            i--;
        }

        while(j>0)
        {
            s=s+word2[j-1];
            j--;
        }
      
        reverse(s.begin(),s.end());
      return s;
    
    }
};