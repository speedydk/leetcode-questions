class Solution {
public:
    
    void cal(vector<int>&cand, vector<vector<int>>&ans, vector<int>&contri, int& target, int i, int sum, int& size)
    {
        //base condition
        if(sum == target)
        {
            ans.push_back(contri);
            return;
        }
        
        if(i == size || sum>target)
            return;
        
        contri.push_back(cand[i]);
        cal(cand, ans, contri, target, i+1, sum + cand[i], size);
        int j=i;
        while(j+1<size && cand[i] == cand[j+1])
            j++;
        contri.pop_back();
        cal(cand, ans, contri, target, j+1, sum, size);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        vector<vector<int>>ans;
        vector<int>contri;
        int size= cand.size();
        int sum= 0;
        cal(cand, ans, contri, target, 0, sum, size);
        return ans;
    }
};