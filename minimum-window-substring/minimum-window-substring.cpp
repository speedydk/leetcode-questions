class Solution {
public:
    string minWindow(string s, string t) {
        int d = 100000;
        vector<int>arr(256,d);
        int count = 0;
        
        for(char ch:t)                 //Doubt
            arr[ch]=0;
        
        for(char ch:t)
            arr[ch]++;
              
        for(int i:arr)
            if(i!=d)
                count++;
        
        string k="";
        int j = 0, i = 0, len = INT_MAX;
        
        while(j<=i && i<s.length())
        {
            while(count && i<s.length())
            {
                if(arr[s[i]]!=d)
                {
                    arr[s[i]]--;
                    if(arr[s[i]]==0)
                        count--;
                }
                
                i++;
            }
            
            while(!count)
            {
                if(len>(i-j))
                {
                    len = i-j;
                    k= s.substr(j,len);
                }
                
                if(arr[s[j]]!=d)
                {
                    arr[s[j]]++;
                    if(arr[s[j]]==1)
                        count++;
                }
                j++;
            }
        }
        return k;
    }
};