class Solution {
public:
    
    
    // Using Priority_Queue
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>que;
        vector<int>ans;
        int n= nums.size();
        
        for(int i =0; i<k; i++)
            que.push({nums[i],i});
        
        ans.push_back(que.top().first);
        
        for(int i=k; i<n; i++)
        {
            que.push({nums[i],i});
            while(que.top().second<= i-k)
                que.pop();
            
            ans.push_back(que.top().first);
        }
        
      return ans;
    }
};