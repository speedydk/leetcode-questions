/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void cal(TreeNode* root, int sum, vector<vector<int>>&ans, vector<int>contri)
    {
        if(!root)
            return;
        
        else if(!root->left && !root->right && root->val==sum)
        {
            contri.push_back(root->val);
            ans.push_back(contri);
        }
        
            contri.push_back(root->val);
            sum=sum-root->val;
            cal(root->left, sum, ans, contri);
            cal(root->right, sum, ans, contri);
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>ans;
        vector<int>contri;
        
        cal(root,targetSum, ans, contri);
        return ans;
    }
};