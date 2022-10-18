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
        ListNode* cur = head;
        int sz = 0;
        while(cur != nullptr){
            sz++;
            cur = cur -> next;
        }
        if( n == sz)
            return head -> next;
        cur = head;
        for(int i = 1; i < sz - n; i++){
            cur = cur -> next;
        }
        cur -> next = cur -> next -> next;
        return head;
    }
};
