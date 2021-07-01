class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<tuple<int, int, int>>que;
        int row = grid.size();
        int col = grid[0].size();
        int max_time = 0;
        
        for(int i = 0; i<grid.size(); i++)
        {
            for(int j = 0; j< grid[i].size(); j++)
            {
                if(grid[i][j] == 2)
                    que.push({i , j, 0});
            }
        }
        
        while(!que.empty())
        {
            int len = que.size();
            
            for(int l = 1; l<=len; l++)
            {
                auto[i, j, time] = que.front();
                que.pop();
                
                max_time = max(max_time, time);
                if(i+1 < row && grid[i+1][j] == 1)
                {
                    grid[i+1][j] = 2;
                    que.push({i+1, j ,time+1});
                }
                
                if(i-1>=0 && grid[i-1][j] == 1)
                {
                    grid[i-1][j] = 2;
                    que.push({i-1, j ,time+1});
                }
                
                if(j+1 <col  && grid[i][j+1] == 1)
                {
                    grid[i][j+1] = 2;
                    que.push({i, j+1 ,time+1});
                }
                
                if(j-1>=0 && grid[i][j-1] == 1)
                {
                    grid[i][j-1] = 2;
                    que.push({i, j-1 ,time+1});
                }
            } 
        }
        
        for(int i = 0; i<grid.size(); i++)
        {
            for(int j = 0; j< grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                    max_time = -1;
            }
        }
        
        return max_time;
        
    }
};