class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
             
        int row= matrix.size(), i= 0;
        int col= matrix[0].size(), j=col-1;
        
        while(j>=0 && i<row)
        {
            if(matrix[i][j]<target)
            {
                i++;
                continue;
            }
            
            if(matrix[i][j]>target)
            {
                j--;
                continue;
            }
            
            return true;
        }
        return false;
    }
};