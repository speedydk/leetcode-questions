class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>ans;
        stack<int>st;
        unordered_map<int, int>rec;
        int n= nums2.size();
        rec[nums2[n-1]]= -1;
        st.push(nums2[n-1]);
        
        for(int i= n-2; i>=0; i--)
        {
            if(st.empty())
            {
                st.push(nums2[i]);
                rec[nums2[i]]=-1;
            }
            
            else if(nums2[i]<st.top())
            {
                rec[nums2[i]]= st.top();
                st.push(nums2[i]);
            }
            
            else
            {
                while(!st.empty() && st.top()<=nums2[i])
                    st.pop();
                
                if(st.empty())
                {
                    st.push(nums2[i]);
                    rec[nums2[i]]=-1;
                }
                
                else
                {
                    rec[nums2[i]]= st.top();
                    st.push(nums2[i]);
                }
            }
        }
        
        for(int i=0; i<nums1.size(); i++)
        ans.push_back(rec[nums1[i]]);
        
        return ans;
        
    }
};