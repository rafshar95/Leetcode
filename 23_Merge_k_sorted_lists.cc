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
    ListNode* MergeKListsUsingPQ(vector<ListNode*>& lists, std::priority_queue<pair<int,int>, vector<std::pair<int,int>>, std::greater<pair<int,int> >>& first_values){
        if(first_values.empty())
            return nullptr;
        int index_with_min_value = first_values.top().second;
        first_values.pop();
        ListNode* head = new ListNode(lists[index_with_min_value] -> val);
        lists[index_with_min_value] = lists[index_with_min_value] -> next;
        if(lists[index_with_min_value] != nullptr){
            first_values.push(make_pair(lists[index_with_min_value] -> val, index_with_min_value));
        }
        ListNode* rest = MergeKListsUsingPQ(lists, first_values);
        head -> next = rest;
        return head;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        std::priority_queue<pair<int, int>, std::vector< pair<int,int>>, std::greater<std::pair<int,int>>> first_values;
        for(int i = 0; i < lists.size(); i++)
            if(lists[i] != nullptr){
               first_values.push(make_pair(lists[i] -> val,i));
            }
        return MergeKListsUsingPQ(lists, first_values);



    }
};
