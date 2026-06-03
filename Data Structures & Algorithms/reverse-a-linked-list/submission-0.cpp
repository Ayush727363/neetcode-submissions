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
        if(head == NULL || head->next == NULL) return head;
        ListNode* p = head;
        ListNode* q = head->next;
        p->next = NULL;
        while(q != NULL){
            ListNode* t = q;
            q = q->next;
            t->next = p;
            p = t;
        }
        return p;
    }
};
