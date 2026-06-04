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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carr = 0;
        ListNode* h = new ListNode();
        ListNode* p = h;

        while(l1 || l2 || carr > 0){
            int v1=0, v2=0;
            if(l1) {
                v1 = l1->val;
                l1 = l1->next;
            }
            if(l2) {
                v2 = l2->val;
                l2 = l2->next;
            }
            int n = v1 + v2 + carr;
            carr = n/10;
            p->next = new ListNode(n%10);
            p = p->next;
        }

        return h->next;
    }
};
