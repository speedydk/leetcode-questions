class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row= dungeon.size();
        int col= dungeon[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));
        dp[row-1][col-1]= (dungeon[row-1][col-1] > 0 ? 0 : dungeon[row-1][col-1]);
        
        for(int i=row-2; i>=0; i--)
        {
            int diff= dp[i+1][col-1] + dungeon[i][col-1];
            dp[i][col-1]= diff>0 ? 0 : diff;
        }
        
        for(int i=col-2; i>=0; i--)
        {
            int diff= dp[row-1][i+1] + dungeon[row-1][i];
            dp[row-1][i]= diff>0 ? 0 : diff;
        }
        
        for(int i=row-2; i>=0; i--)
        {
            for(int j= col-2; j>=0; j--)
            {
                int diff= dungeon[i][j] + max(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = diff>0 ? 0 : diff;
            }
        }
        return dp[0][0]>0 ? 1 : abs(dp[0][0]) + 1;
    }
};