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
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

using namespace std;
static const size_t ARENA_SIZE = 1 << 26; 
alignas(max_align_t) static unsigned char arena[ARENA_SIZE];
static size_t arena_pos = 0;

void* operator new(size_t sz) {
    size_t aligned = (sz + alignof(max_align_t) - 1) & ~(alignof(max_align_t) - 1);
    if (arena_pos + aligned > ARENA_SIZE) {
        throw bad_alloc();
    }
    void* ptr = arena + arena_pos;
    arena_pos += aligned;
    return ptr;
}

void operator delete(void*) noexcept {}
void operator delete(void*, size_t) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete[](void *, size_t) noexcept {}