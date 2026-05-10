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

    bool solve(TreeNode* root, int l , int r)
    {
        if(!root) return true;
        if(root->val > r or root->val <l) return false;

        return solve(root->left,l,root->val-1) and solve(root->right,root->val+1,r);
    }
    bool isValidBST(TreeNode* root) {

        return solve(root,-1001,1001);
        
    }
};
