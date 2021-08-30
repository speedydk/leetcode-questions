class Solution {
public:
    
    void cal(int k, int n, int i, vector<vector<int>>&ans, vector<int>contri)
    {
        //base condition
        
        if(k==0 || i>9)
            return;
        
        else if(k==1 && n-i==0)
        {
            contri.push_back(i);
            ans.push_back(contri);
            return;
        }
        
        
        cal(k, n, i+1, ans, contri);
        contri.push_back(i);
        cal(k-1, n-i, i+1, ans, contri);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>contri;
        cal(k, n, 1, ans, contri);
        
        return ans;
    }
};