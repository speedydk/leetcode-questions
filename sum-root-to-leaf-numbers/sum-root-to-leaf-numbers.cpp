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
    
    void cal(TreeNode* root, int num, int& sum)
    {
        if(!root)
        return;
        
        if(!root->left && !root->right)
        {
            num = num*10 + root->val;
            sum = sum + num;
            return;
        }
        
        num = num*10 + root->val;
        cal(root->left, num, sum);
        cal(root->right, num, sum);
        
    }
    
    int sumNumbers(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int num=0;
        int sum=0;
        
        cal(root,num,sum);
        return sum;
        
    }
};