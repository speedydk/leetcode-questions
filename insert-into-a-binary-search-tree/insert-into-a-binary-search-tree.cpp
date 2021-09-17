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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        
        TreeNode* ptr = new TreeNode(val);
        TreeNode* p = NULL, *m = root;
        
        while(root)
        {
            p = root;
            if(root->val > val)
                root = root->left;
            
            else
                root = root->right;
        }
        
        if(!p)
            return ptr;
        
        p->val > val ? p->left = ptr : p->right = ptr;
        return m;
    }
};