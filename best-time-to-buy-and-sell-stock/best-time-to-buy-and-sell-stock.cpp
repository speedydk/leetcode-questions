class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int purc= prices[0];
        
        int maxi= 0;
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i]>purc)
                maxi= max(maxi, prices[i] - purc);
            
            else
                purc= prices[i];
        }
        
        return maxi;
        
    }
};