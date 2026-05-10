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

    void solve(TreeNode* root, int pathMax, int &ans)
    {
        if(!root) return;

        if(root->val>=pathMax)
        {
            ans++;
        }
        pathMax = max(pathMax, root->val);


        //cout<<"Debug: "<<root->val<<" "<<pathMax<<endl;
        solve(root->left, pathMax,ans);
        solve(root->right,pathMax, ans);

    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        int pathMax = -1e9;

        solve(root,pathMax,ans);

        return ans;
    }
};
