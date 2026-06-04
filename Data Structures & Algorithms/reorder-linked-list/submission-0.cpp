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
        int n =0;
        ListNode* p = head;
        while(p){
            p=p->next;
            n++;
        }
        p=head;
        for(int i =1; i< (n+1)/2; i++){
            p=p->next;
        }
        ListNode* q = p->next;
        p->next = NULL;
        while(q){
            ListNode* t = q;
            q = q->next;
            t->next=p;
            p=t;
        }
        q=p;
        p=head;
        n = n/2;
        while(n > 0){
            ListNode* t = q;
            q = q->next;
            t->next = p->next;
            p->next = t;
            p=t->next;
            n--;
        }
    }
};
