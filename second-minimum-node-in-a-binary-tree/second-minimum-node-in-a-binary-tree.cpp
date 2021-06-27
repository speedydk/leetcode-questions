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
    
    int secMin = INT_MAX;
	int smallest;
	int boolean=false;

	void findSecondMin(TreeNode* root){
		if(root==NULL) return;
		if(root->val>smallest&&root->val<=secMin){
			secMin = root->val;
			boolean=true;
		}
		findSecondMin(root->left);
		findSecondMin(root->right);
	}

    int findSecondMinimumValue(TreeNode* root) {
        smallest = root->val;
        findSecondMin(root);
        return (boolean)?secMin:-1;
    }
};