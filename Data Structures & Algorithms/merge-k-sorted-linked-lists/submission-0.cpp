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
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
public:
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);
        ListNode* q = head;
        for(int i=0; i<lists.size(); i++){
            pq.push(lists[i]);
        }
        while(!pq.empty()){
            ListNode* p = pq.top();
            pq.pop();
            if(p->next) pq.push(p->next);
            q->next = p;
            q = q->next;
        }
        return head->next;
    }
};
