class Solution {
public:
    
    bool check(int i, int j, int row, int col, vector<vector<int>>&grid)
    {
        return (i>=0 && i<row && j>=0 && j<col && grid[i][j]==1);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int per=0;
        int row= grid.size();
        int col= grid[0].size();
    
        vector<vector<int>>arr={ {1,0}, {0,1}, {-1,0}, {0,-1}};
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                int count= 0;
                if(grid[i][j]==1)
                {
                    for(auto it: arr)
                    {  
                        int x= i+it[0];
                        int y= j+it[1];
                        
                        if(check(x,y,row,col,grid))
                            count++;
                    }
                    per+= 4-count;
                }
            }
        }
        return per;
    }
};