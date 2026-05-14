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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        queue<TreeNode*>q;
        q.push(root);
        string ans = "";

        while(!q.empty())
        {
            auto root = q.front(); q.pop();

            if(root==NULL)
            {
                ans+="#|"; continue;
            }
            ans+=to_string(root->val);
            ans+="|";  // pipe to mark end if number is 100 so it is taken as 1 value and not 3
            q.push(root->left);
            q.push(root->right);
        }
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        vector<string>nodes;

        string pre = "";

        for(auto & x : data)
        {
            if(x=='|')
            {
                nodes.push_back(pre);
                pre="";
            }
            else
            {
                pre+=x;
            }
        }

        if(nodes[0]=="#") return NULL;

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        int i = 1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty() && i<nodes.size())
        {
            auto head = q.front(); q.pop();

            if(nodes[i]!="#")
            {
                head->left = new TreeNode(stoi(nodes[i]));
                q.push(head->left);
            }
            i++;


            if(nodes[i]!="#")
            {
                head->right = new TreeNode(stoi(nodes[i]));
                q.push(head->right);
            }
            i++;
        }

        return root;
    }
};
