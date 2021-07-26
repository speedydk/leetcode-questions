class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        if(n<=2)
            return 0;
        vector<int>pre(n,height[0]);
        vector<int>suf(n,height[n-1]);
        
        int water_trap=0;
        
        for(int i=1; i<n; i++)
        {
            pre[i]= max(pre[i-1],height[i]);
            suf[n-i-1]= max(suf[n-i], height[n-i-1]);
        }
        
        for(int i=1; i<n-1; i++)
            water_trap+= min(pre[i],suf[i])-height[i];
        
        return water_trap;
    }
};