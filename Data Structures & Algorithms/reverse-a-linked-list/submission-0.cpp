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
    ListNode* reverseList(ListNode* head) {
        
        auto itr = head;
        ListNode* prev = nullptr;

        while(itr!=nullptr)
        {
            auto nn = itr->next;
            itr->next = NULL;
            itr->next = prev;
            prev=itr;
            itr = nn;
        }

        return prev;
    }
};
