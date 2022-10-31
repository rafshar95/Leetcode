/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void CopyGraph(Node* node, std::unordered_map<int, Node*>& value_to_copy_node){
        Node* copy_current_node = value_to_copy_node[node -> val];
        for(int i = 0; i < node -> neighbors.size(); i++){
            Node* neighbor = node -> neighbors[i];
            if(value_to_copy_node.find(neighbor -> val) == value_to_copy_node.end()){
                Node* next_copy_node = new Node(neighbor -> val);
                value_to_copy_node[neighbor -> val] = next_copy_node;
                CopyGraph(neighbor, value_to_copy_node);
            }
            bool is_in_neighbors = false;
            for(int j = 0; j < copy_current_node -> neighbors.size(); j++){
                Node* neighbor_copy = copy_current_node -> neighbors[j];
                if(neighbor_copy -> val == neighbor -> val)
                    is_in_neighbors = true;
            }
            if(!is_in_neighbors){
                copy_current_node -> neighbors.push_back(value_to_copy_node[neighbor -> val]);
                value_to_copy_node[neighbor -> val] -> neighbors.push_back(copy_current_node);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        Node* result = new Node(node -> val);
        std::unordered_map<int, Node*> value_to_copy_node;
        value_to_copy_node[node -> val] = result;
        CopyGraph(node, value_to_copy_node);


        return result;
    }
};
