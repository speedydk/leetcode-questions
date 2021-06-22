class Solution {
public:
    
    string IPv4(string a)
    {            
        a=a+".";
        int i=0;
        
        while(i<a.length())
        {
            int first=0;
            int size=0;
            if( (i+1<a.length() && a[i]=='0' && a[i+1]!='.')  || (i+1<a.length() && a[i]=='.' && a[i+1]=='.'))
                    return "Neither";
            
            while(i<a.length() && a[i]!='.')
            { 
                if(!(a[i]>='0' && a[i]<='9'))
                    return "Neither";
                
                first=first*10+(a[i]-'0');
                i++;
                size++;
            }
            
            //cout<<first<<endl;
            
            if(!(first>=0 && first<=255) || size==0)
                return "Neither";
            
            i++;
        }
        
        return "IPv4";
        
    }
    
    string IPv6(string a)
    {
        a=a+":";
        int i=0;
        
        while(i<a.length())
        {
            string s="";
            while(i<a.length() && a[i]!=':')
            {
                if(!(a[i]>='0' && a[i]<='9' || a[i]>='a' && a[i]<='f' || a[i]>='A' && a[i]<='F'))
                    return "Neither";
                
                s=s+a[i];
                //cout<<a[i]<<" ";
                i++;
            }
            
            //cout<<s<<endl;
            
            if(!(s.length()>=1 && s.length()<=4))
                return "Neither";
            i++;
                
        }
        return "IPv6";
    }
    
    string validIPAddress(string IP) {
        
        int len=IP.length();
        int count=0;
        
        for(char s:IP)
        {
            if(s=='.' || s==':')
                count++;
        }
        
        //cout<<count;
        
        if(!(count==3 || count==7))
            return "Neither";
        
        if(count==3 && len>15)
            return "Neither";
        
        else if(count==7 && len>39)
            return "Neither";
        
        return count==3?IPv4(IP):IPv6(IP);
    }
};