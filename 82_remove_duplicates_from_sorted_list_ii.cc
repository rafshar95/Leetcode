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
    ListNode* deleteDuplicates(ListNode* head) {
        int number_of_nodes = 0;
        ListNode* new_head;
        ListNode* new_cur;
        ListNode* cur = head;
        int last_val = -1;
        while(cur != nullptr){
            if((cur == head || cur -> val != last_val) && (cur -> next == nullptr || cur -> next -> val != cur -> val)){
                if(!number_of_nodes){
                    new_head = cur;
                    new_cur = cur;
                }
                else{
                    new_cur -> next = cur;
                    new_cur = new_cur -> next;
                }
                number_of_nodes++;
            }

            last_val = cur -> val;
            cur = cur -> next;
        }
        if(!number_of_nodes)
            return nullptr;
        new_cur -> next = nullptr;
        return new_head;

    }
};
