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

    ListNode* Merge(ListNode* a, ListNode* b)
    {
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        if(a==NULL) return b;
        if(b==NULL) return a;
        while(a!=NULL && b!=NULL)
        {
            if(a->val<=b->val)
            {
                ans->next = a;
                a = a->next;
            }
            else
            {
                ans->next = b;
                b = b->next;
            }
            ans = ans->next;
        }

        if(a!=NULL)
        {
            ans->next=a;
        }
        if(b!=NULL)
        {
            ans->next = b;
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size()==0) return NULL;

        ListNode* ans = lists[0];

        for(int i = 1;i<lists.size();i++)
        {
            ans = Merge(ans, lists[i]);
        }

        return ans;

        
    }
};
