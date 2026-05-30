/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    map<int,vector<int>>adj;
    set<int>vis;
    void solve(Node* node, Node* par)
    {
        if(node==NULL or vis.find(node->val)!=vis.end()) return;

        adj[node->val];
        vis.insert(node->val);

        for(auto & x : node->neighbors)
        {


           adj[node->val].push_back(x->val);
                       if(x==par) continue;
           solve(x, node);
        }

    }

    Node* create(Node* n)
    {
        if(n==NULL) return n;
        map<int, Node*>mp;

        for(auto & x : adj)
        {
            if(!mp.contains(x.first))
            {
                mp[x.first] = new Node(x.first);
            }

            auto node = mp[x.first];

            for(auto & y : x.second)
            {
                if(!mp.contains(y))
                {
                    mp[y] = new Node(y);
                }

                node->neighbors.push_back(mp[y]);
            }
        }

        return mp[n->val];
    }
    Node* cloneGraph(Node* node) {
        solve(node, NULL);

        for(auto & x : adj)
        {
            cout<<x.first<<" : ";
            for(auto & y : x.second)
            cout<<y<<" ";
            cout<<endl;
        }
        return create(node);

        return NULL;

        
    }
};
