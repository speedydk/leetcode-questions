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
    
    int helper(TreeNode* root, int& m)
    {
        if(!root)
            return 0;
        
        int left= root->left ? helper( root->left, m ) : 0;
        int right= root->right ? helper( root->right, m ) : 0;
        
        left=(root->left && root->left->val==root->val) ? left+1 : 0;
        right=(root->right && root->right->val==root->val) ? right+1 : 0;
        m=max(m,left+right);
        return max(left,right);
            
    }
    
    int longestUnivaluePath(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int res=0;
        helper(root, res);
        
        return res;
        
    }
};