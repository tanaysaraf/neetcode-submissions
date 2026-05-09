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

    int solve(TreeNode* root, int &ans)
    {
        if(!root) return 0;

        int l = solve(root->left, ans);
        int r = solve(root->right, ans);

        int ansPassThroughMe = 1 + max(l,r);
        int iAmAns = r+l+1;

        ans = max(ans, max(iAmAns, ansPassThroughMe));

        return ansPassThroughMe;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int ans = 0;

        solve(root,ans);
        return ans-1;
    }
};
