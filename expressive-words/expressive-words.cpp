class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        
        int count=0;
        int size=0, k=0;
        for(auto st: words)
        {
            size=0, k=0;
            bool flag= true;
            while(size<s.length() && k<st.length() && s[size]==st[k])
            {
                int local_count=1; 
                int mapp=1;
                while(size+1<s.length() && s[size+1]==s[size])
                {
                    local_count++;
                    size++;
                }
                
                while(k+1<st.length() && st[k+1]==st[k])
                {
                    mapp++;
                    k++;
                }
                
                if(!((local_count==mapp) || (local_count>=mapp && local_count>=3)))
                {
                    flag= false;
                    break;
                }
                size++;
                k++;
            }
            
            if(flag && size==s.length() && k==st.length())
                count++;
        }
        return count;
    }
};