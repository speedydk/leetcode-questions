class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int size= pairs.size();
        vector<int>dp(size,1);
        int count=0;
        for(int i=0; i<size; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(pairs[i][0]>pairs[j][1] && dp[i]<=dp[j])
                    dp[i]++;
            }
        }
        
        for(auto it: dp)
            count= max(count,it);
        return count;
    }
};