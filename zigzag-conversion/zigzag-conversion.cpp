class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows==1 || s.length()<=numRows)
            return s;
        
        vector<string>ans(numRows,"");
        bool flag=true;
        int c;
        
        for(int i=0;i<s.length();i++)
        {
            c=0;
            while(i<s.length() && c<numRows)
            {
                ans[c].push_back(s[i++]);
                c++;
            }
                                 
            c=c-2;
            while(i<s.length() && c>0)
            {    
                ans[c].push_back(s[i++]);
                c--;
            }
            
            i--;
        }
                                 
        s="";
    
        for(int i=0;i<numRows;i++)
        s=s+ans[i];
                        
        return s;
                                 
    }
};