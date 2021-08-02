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

    TreeNode* Tree(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int>&maps, int start, int end, int& index)
    {
        if(start>end)
            return NULL;
    
            TreeNode* root= new TreeNode(postorder[index]);
            
            int ele= maps[postorder[index--]];
            root->right= Tree(inorder, postorder, maps, ele+1, end, index);
            root->left= Tree(inorder, postorder, maps, start, ele-1, index);
            
            return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
     
        unordered_map<int,int>maps;
        for(int i=0; i<inorder.size(); i++)
            maps[inorder[i]]=i;
        
        int post_order= postorder.size()-1;
        return Tree(inorder, postorder, maps, 0, post_order, post_order);
        
    }
};