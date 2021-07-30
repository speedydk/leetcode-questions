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
    
    void longest(TreeNode* root, int left, int right, int& ans)
    {
        if(!root)
        return;
        
        ans= max(ans,max(left,right));
    
        longest(root->left,0,left+1,ans);
        longest(root->right,right+1,0,ans);        
    }
    
    int longestZigZag(TreeNode* root) {
        
        int left=0, right=0, ans=0;
        longest(root,left,right,ans);
        return ans;
        
    }
};