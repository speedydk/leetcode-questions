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
     
    TreeNode * helper(TreeNode* root,vector<int>& preorder,int i)
    {
        if(root==NULL)
        {
            TreeNode * node=new TreeNode(preorder[i]);
            return node;
        }
        
            if(preorder[i]<  root->val)
           root->left=helper(root->left,preorder,i);
        
        else
            root->right=helper(root->right,preorder,i);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++)
            helper(root,preorder,i);
        
        return root;
    }
};