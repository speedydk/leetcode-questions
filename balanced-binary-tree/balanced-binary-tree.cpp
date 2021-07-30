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
    
    int ischeck(TreeNode* root, bool & ans)
    {
        //base condition
        if(ans == false || !root)
            return 0;
        
        int left= ischeck(root->left,ans);
        int right= ischeck(root->right,ans);
        
        if(abs(left-right)>1)
            ans= false;
        
        return 1+max(left,right);
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans= true;
        ischeck(root,ans);
        return ans;
    }
};