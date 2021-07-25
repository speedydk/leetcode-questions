class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>fre(256,0);
        int res=0, j=0;
        
        for(int i=0; i<s.length(); i++)
        {
            while(j<s.length() && fre[s[j]]==0)
            {
                fre[s[j]]++;
                j++;
            }
            
            res= max(res,j-i);
            fre[s[i]]--;
        }
        return res;
    }
};