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

        map<int,int>mp;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& i, int l ,int r)
    {
        if(l>r) return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = solve(preorder, inorder, i, l,mp[root->val]-1);
        root->right = solve(preorder, inorder, i, mp[root->val]+1, r);

        return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        int idx=0;
        for(int i = 0 ;i<n;i++)
        {
            mp[inorder[i]]=i;
        }

        return solve(preorder, inorder,idx, 0, n-1);
    }
};
