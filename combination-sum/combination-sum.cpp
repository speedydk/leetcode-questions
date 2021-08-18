class Solution {
public:
    
    void cal(vector<int>&cand, int& targ, vector<int>&contri, vector<vector<int>>&ans, int i,int& size,int sum)
    {
        //base condition
        if(sum == targ)
        {
            ans.push_back(contri);
            return;
        }
        
        if(i==size || sum>targ)
            return;
        
        contri.push_back(cand[i]);
        cal(cand, targ, contri, ans, i, size, sum + cand[i]);
        contri.pop_back();
        cal(cand, targ, contri, ans, i + 1, size, sum);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>>ans;
        vector<int>contri;
        int size= cand.size();
        int sum=0;
        cal(cand,target,contri,ans,0,size,sum);
        return ans;
    }
};