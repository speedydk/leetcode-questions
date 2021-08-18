class Solution {
public:
    
    bool check_pali(string s)
    {
        int i=0;
        int j=s.length()-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
               return false; 
            i++;
            j--;
        }
        
        return true;
    }
    
    void cal(string s, vector<vector<string>>&ans, vector<string>&contri, int i, int& len)
    {
        if(i==len)
        {
            ans.push_back(contri);
            return;
        }
        
        string k="";
        for(int j=i; j<len; j++)
        {
            k=k+s[j];
            if(check_pali(k))
            {
                contri.push_back(k);
                cal(s,ans,contri,j+1,len);
                contri.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>contri;
        int len= s.length();
        cal(s,ans,contri,0,len);
        return ans;
    }
};