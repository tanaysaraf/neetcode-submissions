/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {

        // Break on half
        auto n1 = head;
        auto n2 = head;
        auto lastN = head;
        while(n1 && n2 && n2->next)
        {
            lastN = n1;
            n1 = n1->next;
            n2 = n2->next->next;
        }

        if(n2!=NULL)
        {
            lastN = n1;
            n1 = n1->next;
        }

        //cout<<"n1 "<<n1->val<<endl;
        // n1 is now at head
        lastN->next = NULL;

        // reverse this now
        ListNode* prev = NULL;
        auto itr = n1;

        while(itr!=NULL)
        {
            auto nn = itr->next;
            itr->next = prev;
            prev = itr;
            itr = nn;
        }

        // prev is head of this reversed list.
        n1 = prev;

        // merge them



        auto ans = head;

        // while(head!=NULL)
        // {
        //     cout<<head->val<<" ";
        //     head = head->next;
        // }
        // cout<<endl;
        //  while(n1!=NULL)
        // {
        //     cout<<n1->val<<" ";
        //     n1 = n1->next;
        // }


        while(head!=NULL and n1!=NULL)
        {
            auto nn1 = head->next;
            head->next = n1;
            auto nn2 = n1->next;
            n1->next = nn1;
            head = nn1;
            n1 = nn2;
        }

        head = ans;

        //return ans;
        
    }
};
