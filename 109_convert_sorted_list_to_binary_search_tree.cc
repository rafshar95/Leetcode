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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* cur = head;
        if(head == nullptr)
            return nullptr;
        if(head -> next == nullptr){
            return new TreeNode(head -> val);
        }
        int n = 0;
        while(cur != nullptr){
            n++;
            cur = cur -> next;
        }
        cur = head;
        ListNode* tail = nullptr;
        for(int i = 1; i <= (n - 1) / 2; i++){
            tail = cur;
            cur = cur -> next;
        }
        if(tail != nullptr)
            tail -> next = nullptr;
        TreeNode* root = new TreeNode(cur -> val);
        root -> left = (tail != nullptr) ? sortedListToBST(head) : nullptr;
        root -> right = sortedListToBST(cur -> next);
        return root;
    }
};
