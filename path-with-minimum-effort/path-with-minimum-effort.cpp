class Solution {
public:    
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row= heights.size(); 
        int col= heights[0].size();
        
        vector<vector<int>>ans(row,vector<int>(col,INT_MAX));
        priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>>pq;
        
        ans[0][0]=0;
        pq.push({0,{0,0}});
        
        vector<vector<int>>check={ {1,0}, {0,1}, {0,-1}, {-1,0} };
        
        while(!pq.empty())
        {
            int i=pq.top().second[0];
            int j=pq.top().second[1];
            int dis=pq.top().first;
            
            pq.pop();
            
            for(auto it: check)
            {
                int x= i + it[0];
                int y= j + it[1];
                
                if(x>=0 && y>=0 && x<row && y<col)
                {
                    int diff= max(dis,abs(heights[x][y]-heights[i][j]));
                    if(ans[x][y]>diff)
                    {
                        ans[x][y]=diff;
                        pq.push({ans[x][y],{x,y}});
                    }
                }
            }
        }
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
        
        return ans[row-1][col-1];
    }
};