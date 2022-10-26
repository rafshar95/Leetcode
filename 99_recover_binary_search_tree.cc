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
    void dfs(TreeNode* root, TreeNode*& prev_node, TreeNode*& greater_node, TreeNode*& smaller_node){
        if(root -> left != nullptr)
            dfs(root -> left, prev_node, greater_node, smaller_node);
        if(prev_node != nullptr && greater_node == nullptr && prev_node -> val > root -> val)
            greater_node = prev_node;
        if(prev_node != nullptr && prev_node -> val > root -> val)
            smaller_node = root;
        prev_node = root;
        if(root -> right != nullptr)
            dfs(root -> right, prev_node, greater_node, smaller_node);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* greater_node = nullptr;
        TreeNode* smaller_node = nullptr;
        TreeNode* predecessor_node = nullptr;
        dfs(root, predecessor_node, greater_node, smaller_node);
        std::swap(smaller_node -> val, greater_node -> val);
    }
};
