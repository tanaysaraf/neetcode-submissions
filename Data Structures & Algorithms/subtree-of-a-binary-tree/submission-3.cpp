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

    bool IsSame(TreeNode* r1, TreeNode* r2)
    {
        if(r1==NULL)
        return r2==NULL;

        if(r2==NULL)
        return r1==NULL;

        if(r1->val==r2->val)
        {
            return IsSame(r1->left, r2->left) && IsSame(r1->right, r2->right);
        }
        
        return false;
    }
    bool isSubtree(TreeNode* r1, TreeNode* r2) {

        if(r1==NULL) return r2==NULL;
        if(r2==NULL) return true;
        if(r1->val==r2->val)
        {
            return IsSame(r1,r2) or isSubtree(r1->left,r2) or isSubtree(r1->right, r2);
        }
        return isSubtree(r1->left,r2) or isSubtree(r1->right, r2);
        
    }
};
