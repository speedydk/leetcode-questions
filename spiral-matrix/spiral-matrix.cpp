class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        
        int left = 0, right = matrix[0].size()-1, top = 0, bot = matrix.size()-1;
        
        while(left<=right && top<=bot)
        {
            for(int i=left; i<=right; i++)
                ans.push_back(matrix[top][i]);
            top++;
            
            if(left<=right)
            for(int i=top; i<=bot; i++)
                ans.push_back(matrix[i][right]);
            right--;
            
            if(top<=bot)
            for(int i=right; i>=left; i--)
                ans.push_back(matrix[bot][i]);
            bot--;
            
            if(left<=right)
            for(int i=bot; i>=top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
        return ans;
    }
};