class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0, start= 0, last= height.size()-1;
        
        while(start<last)
        {
            ans=max(ans,min(height[start],height[last])*(last-start));
            if(height[start]>height[last])
                last--;
            else
                start++;
        }
        
        return ans;
    }
};