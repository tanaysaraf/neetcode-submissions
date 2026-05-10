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
    TreeNode* GetLca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root) return NULL;

        if(root==p or root==q) return root;

        auto left = GetLca(root->left,p,q);
        auto right = GetLca(root->right,p,q);

        if(left!=NULL && right!=NULL) return root;

        if(left!=NULL) return left;
        if(right!=NULL) return right;

        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return GetLca(root,p,q);
    }
};
