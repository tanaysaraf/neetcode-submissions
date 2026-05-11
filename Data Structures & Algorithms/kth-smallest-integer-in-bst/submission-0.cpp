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
    int kthSmallest(TreeNode* root, int k) {

       stack<TreeNode*>q;

       while(root!=NULL)
       {
            q.push(root);
            root = root->left;
       }

       while(q.size())
       {
        auto node = q.top(); q.pop(); k--;

        //cout<<node->val<<endl;

        if(k==0) return node->val;

        if(node->right)
        {
            node = node->right;
            while(node!=NULL)
            {
                    q.push(node);
                    node = node->left;
            }
        }

       }

       return -1;
        
    }
};
