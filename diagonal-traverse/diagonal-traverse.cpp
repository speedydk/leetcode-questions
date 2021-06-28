class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        vector<int>ans;
        map<int, vector<int>>trav;
        int row= mat.size();
        int col= mat[0].size();
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
                trav[i+j].push_back(mat[i][j]);
        }
        
        for(auto i : trav) {
            if((i.first)%2 == 0) 
                reverse(i.second.begin(), i.second.end()); 
            
            for(auto k : i.second) 
                ans.push_back(k);
        }
        return ans;
        
    }
};