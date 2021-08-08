class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        
        while(--numRows)
        {
            vector<int>res;
            res.push_back(1);
            int size= ans.size();
            for(int i=1; i<size; i++)
                res.push_back(ans[size-1][i-1]+ans[size-1][i]);
            res.push_back(1);
            ans.push_back(res);
        }
        return ans;
    }
};