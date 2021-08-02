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
    
    int pre_index= 0;
    TreeNode* build_Tree(vector<int>& preorder, vector<int>& inorder, int start, int end, unordered_map<int,int>&inor) {
        
        if(start>end)
            return NULL;
        
        TreeNode* root= new TreeNode(preorder[pre_index]);
        int ele= inor[preorder[pre_index++]];
        root->left= build_Tree(preorder, inorder, start, ele-1, inor);
        root->right= build_Tree(preorder, inorder, ele+1, end,inor);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int>inor;
        for(int i=0; i<inorder.size(); i++)
            inor[inorder[i]]=i;
            
        int start=0, end=preorder.size()-1;
        return build_Tree(preorder, inorder, start, end, inor);
    }
};