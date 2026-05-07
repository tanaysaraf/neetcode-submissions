/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


class Solution {
public:

    void Debug(Node* head, bool flag)
    {
        if(!flag) return;

        while(head!=NULL)
        {
            cout<<head->val<<" & "<<head->random<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    Node* copyRandomList(Node* head) {

        // we insert node in between and then detach

        if(head==NULL) return NULL;

        auto itr = head;
        auto dummy = head;

        while(itr!=NULL)
        {
            auto nn = itr->next;
            itr->next = new Node(itr->val);
            itr->next->random = NULL;
            itr->next->next = nn;
            itr = nn;
        }

        // Debug 1 Pass
        Debug(head,0);


        // Add random pointers.
        //cout<<head->val<<endl;
        itr = head;
        int cnt = 1;
        while(itr!=NULL)
        {
            auto copyNode = itr->next;
            if(itr->random!=NULL)
            copyNode->random = itr->random->next;
            itr = itr->next->next;

        }

        Debug(head,0);

        // Need to detach them. 
        auto h1 = head;
        auto h2 = head->next;

        auto ans = h2;

        while(h1!=NULL and h2!=NULL)
        {
            auto n1 = h2->next;
            h1->next = h2->next;
            h1 = h1->next;
            if(h1==NULL) break;
            h2->next = h1->next;
            h2 = h2->next;
        }



        return ans;
        
    }
};
