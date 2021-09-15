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
    
    void cal(TreeNode* root, vector<int>&ans)
    {
        //base condition
        if(!root)
            return;
        
        cal(root->left,ans);
        ans.push_back(root->val);
        cal(root->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        cal(root, ans);
        return ans;
    }
};