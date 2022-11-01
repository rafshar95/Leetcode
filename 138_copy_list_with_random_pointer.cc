/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        std::unordered_map <Node*, int> index_of_node_original_list;
        std::unordered_map <int, Node*> node_of_index_new_list;
        Node* cur = head;
        Node* new_head = nullptr;
        Node* new_cur = nullptr;
        Node* new_prev = nullptr;
        int index = 0;
        while(cur != nullptr){
            new_cur = new Node(cur -> val);
            index_of_node_original_list[cur] = index;
            node_of_index_new_list[index] = new_cur;
            if(index == 0)
                new_head = new_cur;
            else
                new_prev -> next = new_cur;
            new_prev = new_cur;
            cur = cur -> next;
            index++;
        }
        cur = head;
        new_cur = new_head;
        while(cur != nullptr){
            if(cur -> random != nullptr)
                new_cur -> random = node_of_index_new_list[index_of_node_original_list[cur -> random]];
            cur = cur -> next;
            new_cur = new_cur -> next;
        }
        return new_head;
    }
};
