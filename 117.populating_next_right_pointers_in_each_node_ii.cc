/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void ConnectNext(Node*& first_child_node, Node*& last_child_node, Node*& next_child_node){
        if(next_child_node == nullptr)
            return;
        if(first_child_node == nullptr){
            first_child_node = next_child_node;
            last_child_node = next_child_node;
        }
        else{
            last_child_node -> next = next_child_node;
            last_child_node = last_child_node -> next;
        }
    }
    void ConnectAllLevels(Node* start_chain_node){
        Node* current_node = start_chain_node;
        Node* first_child_node = nullptr;
        Node* last_child_node = nullptr;
        while(current_node != nullptr){
            ConnectNext(first_child_node, last_child_node, current_node -> left);
            ConnectNext(first_child_node, last_child_node, current_node -> right);
            current_node = current_node -> next;
        }
        if(first_child_node == nullptr)
            return;
        ConnectAllLevels(first_child_node);
    }
    Node* connect(Node* root) {
        ConnectAllLevels(root);
        return root;
    }
};
