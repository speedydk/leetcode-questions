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
    TreeNode* build_Tree(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        
        if(start>end)
            return NULL;
        
        TreeNode* root= new TreeNode(preorder[pre_index++]);
        
        int index;
        for(int i=start; i<=end; i++)
        {
            if(inorder[i]==root->val)
            {
                index=i;
                break;
            }
        }
        
        root->left= build_Tree(preorder, inorder, start, index-1);
        root->right= build_Tree(preorder, inorder, index+1, end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int start=0, end=preorder.size()-1;
        return build_Tree(preorder, inorder, start, end);
    }
};