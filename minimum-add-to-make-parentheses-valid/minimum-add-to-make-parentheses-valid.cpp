class Solution {
public:
    int minAddToMakeValid(string A) {
        
    int count=0;
    int ans=0;
    
    for(char ch:A)
    {
        if(ch=='(')
        {
           count++;
           ans++;
        }
        
        else if(count>0)
        {
            count--;
            ans--;
        }
        
        else
           ans++;
    }
    
    return ans++;
        
    }
};