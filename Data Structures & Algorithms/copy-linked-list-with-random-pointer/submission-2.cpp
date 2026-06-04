class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* q = head;
        while(q){
            Node* t = q;
            int val = q->val;
            q=q->next;
            t->next = new Node(val);
            t = t->next;
            t->next = q;
        }
        q = head;
        Node* p = q->next;

        while(p && q){
            if(q->random == NULL) p->random = NULL;
            else p->random = q->random->next;
            if(p->next){
                p = p->next->next;
                q = q->next->next;
            }else break;
        }

        q = head;
        p = q->next;

        Node* h = new Node(-1);
        h->next = p;
        while(p->next && q->next){
            q->next = p->next;
            q = q->next;
            p->next = q->next;
            p = p->next;
        }
        p->next = NULL;
        q->next = NULL;

        return h->next;
    }
};