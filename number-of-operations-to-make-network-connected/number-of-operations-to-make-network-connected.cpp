class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int size = connections.size();
        if(!(size+1>=n))
            return -1;
        
        vector<vector<int>>gra(n);
        
        for(auto it: connections)
        {
            gra[it[0]].push_back(it[1]);
            gra[it[1]].push_back(it[0]);
        }
        
        vector<bool>visited(n,false);
        int count=0;
        for(int i = 0; i<n; i++)
        {
          if(!visited[i])
          {
            queue<int>que;
            que.push(i);
            visited[i]=true;
            count++;
            
            while(!que.empty())
            {
                int x = que.front();
                que.pop();
                
                for(int j=0; j<gra[x].size(); j++)
                {
                    if(!visited[gra[x][j]])
                    {
                        que.push(gra[x][j]);
                        visited[gra[x][j]] = true;
                    }
                }
            }
          }
        }
        
        return count - 1;
    }
};