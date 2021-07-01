class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>>pos(n);
        
        
        int start;
        
        //Graph prepared
        for(int i= 0; i<manager.size(); i++)
        {
            if(manager[i] == -1)
                start = i;
            
            else
                pos[manager[i]].push_back(i);
        }
        
        //Traversing using BFS
        int max_time = 0;
        queue<pair<int, int>>que;
        que.push({start, 0});
        
        while(!que.empty())
        {
            pair <int, int>t= que.front();
            que.pop();
            
            int index = t.first;
            int time = t.second + informTime[index];
            max_time = max( max_time, time);
            for(int i = 0; i<pos[index].size(); i++)
                que.push({pos[index][i], time});    
        }
        
        return max_time;
    }
};