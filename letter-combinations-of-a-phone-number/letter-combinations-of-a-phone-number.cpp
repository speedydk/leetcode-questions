class Solution {
public:
    
    void dfs(string digits, vector<string>& ans, vector<string>& res, int index, string s)
    {
        //base condition
        if(index==digits.size())
        {
            res.push_back(s);
            return;
        }
        
        for(int j=0; j<ans[digits[index]-'0'].size(); j++)
        {
            s.push_back(ans[digits[index]-'0'][j]);
            dfs(digits, ans, res, index+1, s);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string>res;
        if(digits.size()==0)
            return {};
        vector<string>ans={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string path="";
        dfs(digits, ans, res, 0, path);
        
        return res;
    }
};