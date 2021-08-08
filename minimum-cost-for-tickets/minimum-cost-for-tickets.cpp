class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int size= days.size();
        vector<int>dp(days[size-1]+1,INT_MAX);
        dp[0]=0;
        
        int ptr=0;
        
        for(int i=1; i<=days[size-1]; i++)
        {
            if(i==days[ptr])
            {
                int seven= i-7<0 ? 0 : i-7;
                int thirty= i-30<0 ? 0 : i-30;
                
                dp[i]= min(costs[0]+dp[i-1], min(costs[1]+dp[seven],costs[2]+dp[thirty]));
                ptr++;
            }
            
            else
                dp[i]= dp[i-1];
        }
        
        return dp[days[size-1]];
    }
};