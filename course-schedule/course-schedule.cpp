class Solution {
public:
    
    void dfs(vector<vector<int>>&gra, vector<int>&visited, bool & finish_courses, int i)
    {
        visited[i]= 1;
        
        for(int j=0; j<gra[i].size(); j++)
        {
            if(visited[gra[i][j]]==1)
            {
                finish_courses= false;
                return;
            }
            
            if(!visited[gra[i][j]])
                dfs(gra, visited, finish_courses, gra[i][j]);
        }
        
        visited[i]= 2;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>gra(numCourses);
        
        for(auto it: prerequisites)
            gra[it[0]].push_back(it[1]);
        
        vector<int>visited(numCourses,0);
        bool finish_courses= true;
        
        for(int i=0; i<gra.size(); i++)
        {
            dfs(gra,visited,finish_courses,i);
            if(!finish_courses)
                return false;
        }
        return true;
    }
};