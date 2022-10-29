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
    TreeNode* Postorder(TreeNode* root){ //Returns the last node in the subtree rooted at root
        if(root == nullptr)
            return nullptr;
        TreeNode* last_left_node = Postorder(root -> left);
        TreeNode* last_right_node = Postorder(root -> right);
        if(root -> left != nullptr){
            last_left_node -> right = root -> right;
            root -> right = root -> left;
            root -> left = nullptr;
        }
        if(last_right_node != nullptr)
            return last_right_node;
        if(last_left_node != nullptr)
            return last_left_node;
        return root;
    }
    void flatten(TreeNode* root) {
        Postorder(root);
    }
};
