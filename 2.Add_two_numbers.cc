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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        ListNode* res = l3;
        int residual = 0;
        while(l1!= nullptr || l2 != nullptr || residual>0){
            if(l1!= nullptr)
                l3 -> val = l1 -> val;
            if(l2 != nullptr)
                l3 -> val += l2 -> val;
            l3 -> val += residual;
            residual = (l3 -> val) / 10;
            l3 -> val %= 10;
            if(l1 != nullptr)
                l1 = l1 -> next;
            if(l2 != nullptr)
                l2 = l2 -> next;
            if(l1 != nullptr || l2 != nullptr || residual > 0){
                l3 -> next = new ListNode();
                l3 = l3 -> next;
            }
        }
        return res;
    }
};
