class Solution {
public:
    
    void solve(int i, int n, int k, vector<int>&contri, vector<vector<int>>&ans)
    {
        //base condition
        if(k==0)
        {
            ans.push_back(contri);
            return;
        }
        
        if(k<0 || i>n)
            return;
        
        contri.push_back(i);
        solve(i+1, n, k-1, contri, ans);
        contri.pop_back();
        solve(i+1, n, k, contri, ans);
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>>ans;
        vector<int>contri;
        
        solve(1,n,k,contri, ans);
        return ans;
    }
};