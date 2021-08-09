class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>>graph(n+1);
        for(int i=0; i<times.size(); i++)
            graph[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dis(n+1, INT_MAX);
        dis[k]=0;
        pq.push(make_pair(0,k));
        
        while(!pq.empty())
        {
            int dist= pq.top().first;
            int src= pq.top().second;
            pq.pop();
            
            for(int i=0; i<graph[src].size(); i++)
            {
                if(dis[graph[src][i].first] > (dist + graph[src][i].second))
                {
                    int d= dist + graph[src][i].second;
                    pq.push(make_pair(d,graph[src][i].first));
                    dis[graph[src][i].first] = dist + graph[src][i].second;
                }
            }
        }
        
        int time_taken= 0;
        
        for(int i=1; i<dis.size(); i++)
        {
            if(dis[i]==INT_MAX)
                return -1;
            
            time_taken= max(time_taken,dis[i]);
        }
        return time_taken;
    }
};