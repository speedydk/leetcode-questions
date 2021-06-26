class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         
        if(nums.size()<=1)
            return nums.size();
        
        int i=0;
        int j=-1;
        int maxi = INT_MIN;
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            if( nums[i] == 0 )
                k--;
            
            if(k>=0)
            maxi = max (maxi, i-j);
            
            while(k<0)
            {
                if(nums[j+1]==0)
                    k++;
                j++;
            }            
        }
        
        return maxi == INT_MIN ? 0 : maxi;
        
    }
};