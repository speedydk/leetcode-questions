class Solution {
public:
    
    int bits(int num)
    {
        int count=0;
        
        for(int i=0;i<32;i++) {
            if(num & (1<<i))
                count++;
        }
        
        return count;
    }
    
    vector<int> countBits(int num) {
    
        vector<int>ans(num+1);
        for(int i=0;i<=num;i++)
            ans[i] = bits(i);
        
        return ans;
    }
};