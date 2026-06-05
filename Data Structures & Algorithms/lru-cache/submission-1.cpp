struct ListNode {
    int val;
    int ky;
    ListNode* next;
    ListNode* prev;
    
    ListNode(int v, int k){
        val = v;
        ky = k;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
    int c;
    unordered_map<int,ListNode*> mp;
    ListNode* head;
    ListNode* tail;
public:
    LRUCache(int capacity) {
        c = capacity;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        
        head->next = tail;
        tail->prev = head;
    }
    
    void delnode(ListNode* p){
        ListNode* nxt = p->next;
        ListNode* prv = p->prev;
        nxt->prev = prv;
        prv->next = nxt;
    }

    void insnode(ListNode* p){
        ListNode* nxt = head->next;
        head->next = p;
        p->prev = head;
        p->next = nxt;
        nxt->prev = p;
    }

    int get(int key) {
        if(!mp.count(key)){
            return -1;
        }
        ListNode* p = mp[key];
        delnode(p);
        insnode(p);
        return p->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            ListNode* p = mp[key];
            p->val = value;
            p->ky = key;
            delnode(p);
            insnode(p); 
            return;
        }
        else if(mp.size() == c){
            ListNode* p = tail->prev;
            delnode(p);
            mp.erase(p->ky);
            delete p;
        }
        ListNode* p = new ListNode(value, key);
        insnode(p);
        mp[key] = p;

    }
};