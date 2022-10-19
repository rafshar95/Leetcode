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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* cur = head;
        ListNode* last;
        int n = 0;
        while(cur != nullptr){
            last = cur;
            cur = cur -> next;
            n++;
        }
        if(n)
            k %= n;
        if(n <= 1 || k == 0)
            return head;
        cur = head;
        for(int i = 1; i < n - k; i++){
            cur = cur -> next;
        }
        ListNode* new_head = cur -> next;
        cur -> next = nullptr;
        last -> next = head;
        return new_head;


    }
};
