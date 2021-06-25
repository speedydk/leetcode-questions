class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int low=0;
        int high=0;
        vector<int>ans;
        
        while(low<nums1.size() && high<nums2.size())
        {
            if(nums1[low]>nums2[high])
                high++;
            
            else if(nums1[low]<nums2[high])
                low++;
            
            else
            {
                ans.push_back(nums1[low]);
                int left=nums1[low];
                
                while(low<nums1.size() && nums1[low]==left)
                    low++;
                
                while(high<nums2.size() && nums2[high]==left)
                    high++;
                    
            }
        }
        
        return ans;
    }
};