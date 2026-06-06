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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* kth = head;
        for(int i=0; i<k-1; i++){
            if(kth == NULL) return head;
            kth = kth->next;
        }
        ListNode* nxt = kth->next;
        kth->next = NULL;

        ListNode* p = head;
        ListNode* q = NULL;
        while(p){
            ListNode* t = p;
            p = p->next;
            t->next = q;
            q = t;
        }
        ListNode*prv = head;
        head = q;
        while(true){
            ListNode* temp = nxt;
            kth = nxt;
            for(int i=0; i<k-1; i++){
                if(kth == NULL){
                    prv->next = nxt;
                    return head;
                }
                kth = kth->next;
            }
            if(kth == NULL){
                prv->next = nxt;
                return head;
            }
            nxt = kth->next;
            kth->next = NULL;
            p = temp;
            q = NULL;
            while(p){
                ListNode* t = p;
                p = p->next;
                t->next = q;
                q = t;
            }
            prv->next = kth;
            prv = temp;
        }
        return head;
    }
};
