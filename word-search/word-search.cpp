class Solution {
public:
    
    bool dfs(vector<vector<char>>&board, string word, int index, int i, int j, int row, int col)
    {
    
        
        if(i<0 || i==row || j<0 || j==col || board[i][j]!=word[index] || index>=word.length())
            return false;
        
        if(index == word.size()-1)
        return true;
    
        char ch= board[i][j];
        board[i][j]='0';
        
        if(dfs(board, word, index + 1, i+1, j, row, col) || dfs(board, word, index + 1, i, j+1, row, col) || dfs(board, word, index + 1, i-1, j, row, col) || dfs(board, word, index + 1, i, j-1, row, col))
                return true;
        
        board[i][j]=ch;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row= board.size(), col= board[0].size();
        int index=0;
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                    if(dfs(board, word, index, i, j, row, col))
                        return true;
            }
        }
        return false;
    }
};