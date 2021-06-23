class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int>ans(queries.size(),-1);
        
        vector<int>prefix;
        
        int j=0;
        for(int i:arr)
        {   
            j=i^j;
            prefix.push_back(j);
        }
        
        for(int i=0;i<queries.size();i++)
        {
            int a=queries[i][0];
            int b=queries[i][1];
            
            if(a==0)
                ans[i]=prefix[b];
            
            else
                ans[i]=prefix[b]^prefix[a-1];
        }
        
        return ans;
        
    }
};