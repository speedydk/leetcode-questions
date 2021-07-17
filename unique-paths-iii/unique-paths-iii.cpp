class Solution {
public:
    
    vector<vector<int>>x = {{-1,0} , {1,0}, {0,1}, {0,-1}};
    
    void unique_path(int& row,int&col,vector<vector<int>>&grid,vector<vector<bool>>&visited,int a,int b,int count, int& uni_path)
    {
        //base condition
        visited[a][b] = true;
        
        if(grid[a][b] == 2 && count-1==0)
        {
            uni_path++;
            visited[a][b] = false;
            return;
        }
        
        else if(grid[a][b] == 2)
        {
            visited[a][b] = false;
            return;
        }
        
        count=count-1;
        for(auto it: x)
        {
            int x = a + it[0];
            int y = b + it[1];
            
            if( x>=0 && y>=0 && x<row && y<col && !visited[x][y] && grid[x][y]!=-1)
                unique_path(row, col, grid, visited, x, y, count, uni_path);
        }
        visited[a][b] = false;
        return;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int row= grid.size();
        int col= grid[0].size();
        pair<int,int>start;
        pair<int,int>end;
        int count = row * col;
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        int uni_path = 0;
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]==1)
                    start=make_pair(i,j);
                
                else if(grid[i][j] == 2)
                    end=make_pair(i,j);
                
                else if(grid[i][j] == -1)
                    count--;
            }
        }
        
        unique_path(row, col, grid, visited, start.first, start.second, count, uni_path);
        return uni_path;
    }
};