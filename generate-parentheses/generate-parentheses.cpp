class Solution {
public:
    
    void order(int start, int end, int n, string& ptr, vector<string>& ans)
    {
        //base condition
        if(start==n && end==n)
        {
            ans.push_back(ptr);
            return;
        }
        
        else if(end>start || start>n || end>n)
            return;
        
        ptr.push_back('(');
        order(start+1, end, n, ptr, ans);
        ptr.pop_back();
        ptr.push_back(')');
        order(start, end+1, n, ptr, ans);
        ptr.pop_back();
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string ptr="(";
        int start=1, end=0;
        order(start, end, n, ptr, ans);
        return ans;
    }
};