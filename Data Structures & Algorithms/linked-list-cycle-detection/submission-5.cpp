class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode* s = head;
        ListNode* f = head;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
            if(s == f) return true;
        }
        return false;
    }
};