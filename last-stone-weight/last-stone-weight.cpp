class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>pq;
        
        for(auto it: stones)
            pq.push(it);
        
        while(pq.size()>1)
        {
            int k= pq.top();
            pq.pop();
            
            if(pq.empty())
                return k;
            
            else
            {
                int l= pq.top();
                pq.pop();
                
                if(l==k)
                    continue;
                
                pq.push(k-l);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};