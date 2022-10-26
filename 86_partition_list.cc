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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr)
            return head;
        ListNode* less_head;
        ListNode* less_cur;
        ListNode* other_head;
        ListNode* other_cur;
        int less_count = 0;
        int other_count = 0;
        ListNode* cur = head;
        while(cur != nullptr){
            if(cur -> val < x){
                if(less_count){
                    less_cur -> next = cur;
                    less_cur = cur;
                }
                else{
                    less_head = cur;
                    less_cur = less_head;
                }
                less_count++;
            }
            else{
                if(other_count){
                    other_cur -> next = cur;
                    other_cur = cur;
                }
                else{
                    other_head = cur;
                    other_cur = other_head;
                }
                other_count++;
            }
            cur = cur -> next;
        }
        if(other_count)
            other_cur -> next = nullptr;
        if(less_count){
            if(other_count)
                less_cur -> next = other_head;
            return less_head;
        }
        return other_head;
    }
};
