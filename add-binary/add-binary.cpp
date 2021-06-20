class Solution {
public:
    string addBinary(string a, string b) {
        
        if(a.length()<b.length())
            return addBinary(b,a);
        
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
    
        string s="";
        int c=0;
        int i=0;
        
        while(i<a.length() && i<b.length())
        {
            if(c==1)
            {
                if(a[i]=='1' && b[i]=='1')
                    s=s+"1";
                
                else if(a[i]=='1' || b[i]=='1')
                    s=s+"0";
                
                else
                {
                    s=s+"1";
                    c=0;
                }
            }
            
            else
            {
                if(a[i]=='1' && b[i]=='1')
                {    
                    s=s+"0";
                    c=1;
                }
                
                else if(a[i]=='1' || b[i]=='1')
                    s=s+"1";
                
                else
                    s=s+"0";
            }
            
            i++;
            
        }
        
        while(i<a.length())
        {
            if(c==1 && a[i]=='1')
            {
                s=s+"0";
                c=1;
            }
            
            else if(c==1 || a[i]=='1')
            {
                c=0;
                s=s+"1";
            }
            
            else
                s=s+"0";
            
            
            i++;
        }
        
        if(c==1)
            s=s+"1";
        
        reverse(s.begin(),s.end());
        return s;
        
    }
};