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
    
    TreeNode* merge(TreeNode* root)
    {
        if(!root)
            return NULL;
        
        if(!root->left && !root->right)
            return root;
        
        TreeNode* left_most= merge(root->left);
        TreeNode* right_most= merge(root->right);
        
        TreeNode* t= root->right;
        
        if(!left_most)
            return right_most;
        
        if(!right_most)
        {
            root->right= root->left;
            root->left= NULL;
            return left_most;
        }
        
        left_most->left= NULL;
        left_most->right= t;
        root->right= root->left;
        root->left= NULL;
        
        return right_most;
    }
    
    void flatten(TreeNode* root) {
           if(!root)
               return;
        
        if(!root->left && !root->right)
            return;
        
        merge(root);
    }
};