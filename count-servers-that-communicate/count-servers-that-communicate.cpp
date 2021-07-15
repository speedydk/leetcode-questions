class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        queue<pair<int,int>>que;
        
        int ptr=0, ptc=0;
        int total_connected=0;
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == 1)
                    que.push({i,j});
            }
        }
        
        int count = 0;
        
        while(!que.empty())
        {
            auto t= que.front();
            que.pop();
            bool flag = false;
            
            for(int i=0; i<col; i++)
            {
                if(i == t.second)
                    continue;
                
                if(grid[t.first][i] == 1)
                {
                    count++;
                    flag = true;
                    break;
                }
            }
            
            if(!flag)
                for(int i=0; i<row; i++)
                {
                    if(i==t.first)
                        continue;
                    
                    if(grid[i][t.second] == 1)
                    {
                        count++;
                        flag= true;
                        break;
                    }
                }
        }
        
        return count;
    }
};