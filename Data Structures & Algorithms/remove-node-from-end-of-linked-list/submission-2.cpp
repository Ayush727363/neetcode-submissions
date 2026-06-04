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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode d = ListNode(-1, head);
        ListNode* f = &d;
        ListNode* s = &d;
        while(n >= 0){
            f=f->next;
            n--;
        }
        while(f){
            f=f->next;
            s=s->next;
        }
        s->next = s->next->next;
        return d.next;
    }
};
