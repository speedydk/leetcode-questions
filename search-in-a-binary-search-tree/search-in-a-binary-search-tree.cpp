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
    
    void fucnc(TreeNode* root, int& val, TreeNode*& ptr)
    {
        //base condition
        if(!root)
            return;
        
        if(root->val == val)
        {
            ptr = root;
            return;
        }
        
        fucnc(root->left, val, ptr);
        fucnc(root->right, val, ptr);
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        
        TreeNode* ptr = NULL;
        fucnc(root, val, ptr);
        return ptr;
        
    }
};