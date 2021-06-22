class Solution {
public:
    int compareVersion(string a, string b) {
        
        if(a.length()<b.length())
        {
            int l =compareVersion(b,a);
            return -1*l;
        }
        
        a =a + ".";
        b =b + ".";
        
        int i=0,j=0;
        
        while(i<a.length() && j<b.length())
        {
            int first=0;
            int second=0;
            while(i<a.length() && a[i]!='.')
            {
                first =first*10 + (a[i]-'0');
                i++;
            }
            
            while(j<b.length() && b[j]!='.')
            {
                second =second*10 + (b[j]-'0');
                j++;
            }
            
            //cout<<first<<" "<<second<<endl;
            
            if(first<second)
                return -1;
            
            else if(first>second)
                return 1;
            
            else
            {
                i++;
                j++;
            }
        }
        
        
        while(i<a.length())
        {
            if(a[i]!='.' && a[i]-'0'>0)
                return 1;
            
            i++;
        }
        
        return 0;
        
    }
};