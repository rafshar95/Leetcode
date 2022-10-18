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
    ListNode* ReverseOnlyK(ListNode* head, int k) {
        if(k == 1)
            return head;
        ListNode* new_head = ReverseOnlyK(head -> next, k - 1);
        head -> next -> next = head;
        head -> next = nullptr;
        return new_head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        for(int i = 1; i <= k; i++){
            if(cur == nullptr)
                return head;
            cur = cur -> next;
        }
        ListNode* list_suffix = reverseKGroup(cur, k);
        ListNode* new_head = ReverseOnlyK(head, k);
        head -> next = list_suffix;
        return new_head;
    }
};
