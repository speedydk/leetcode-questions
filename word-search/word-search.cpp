class Solution {
public:
    
    bool dfs(vector<vector<char>>&board, string word, int index, int i, int j, int row, int col, vector<vector<bool>>&visited)
    {
    
        if(index == word.size())
        return true;
        
        if(i<0 || i==row || j<0 || j==col || visited[i][j]==true)
            return false;
        
        visited[i][j]=true;
        
        if(board[i][j] == word[index])
        {
            if(dfs(board, word, index + 1, i+1, j, row, col, visited) || dfs(board, word, index + 1, i, j+1, row, col, visited) || dfs(board, word, index + 1, i-1, j, row, col, visited) || dfs(board, word, index + 1, i, j-1, row, col, visited))
                return true;
        } 
        
        visited[i][j]=false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row= board.size(), col= board[0].size();
        vector<vector<bool>>visited(row, vector<bool>(col,false));
        int index=0;
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                    if(dfs(board, word, index, i, j, row, col, visited))
                        return true;
            }
        }
        return false;
    }
};