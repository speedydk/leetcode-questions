class Solution {
public:
    int longestValidParentheses(string s) {
        
        int ans=0;
        
        
        for(int i=0; i<s.length(); i++)
        {
            
            if(s[i]!='(')
            continue;
            
            stack<char>sta;
            sta.push('(');
            for(int j=i+1; j<s.length(); j++)
            {
                if(s[j]=='(')
                    sta.push(s[j]);
                
                else if(s[j]==')' && sta.empty())
                    break;
                
                else
                    sta.pop();
                
                if(sta.empty())
                {
                    ans= max(ans, (j-i)+1);
                }
            }
        }
        return ans;
    }
};