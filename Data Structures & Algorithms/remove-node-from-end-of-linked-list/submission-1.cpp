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
        int s =0;
        ListNode* p = head;
        while(p){
            s++;
            p = p->next;
        }
        s -= n;
        p = new ListNode(-1, head);
        head = p;
        while(s > 0){
            p= p->next;
            s--;
        }

        p->next = p->next->next;
        
        return head->next;
    }
};
