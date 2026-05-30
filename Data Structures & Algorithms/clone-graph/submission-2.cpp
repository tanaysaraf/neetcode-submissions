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
    map<Node*, Node*> mapped;

    Node* solve(Node* node)
    {
        if(node==NULL) return node;

        if(mapped.contains(node))
        return mapped[node];

        Node* copy = new Node(node->val);
        mapped[node]=copy;
        for(auto & x : node->neighbors)
        {
            copy->neighbors.push_back(solve(x));
        }

        return copy;

    }
    Node* cloneGraph(Node* node) {
        return solve(node);
    }
};
