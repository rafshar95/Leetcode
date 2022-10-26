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
    bool IsValidBST(TreeNode*& root, TreeNode*& prev_node){
        if(root -> left != nullptr)
            if(!IsValidBST(root -> left, prev_node))
                return false;
        if(prev_node != nullptr && prev_node -> val >= root -> val)
            return false;
        prev_node = root;
        if(root -> right != nullptr)
            if(!IsValidBST(root -> right, prev_node))
                return false;
        return true;

    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev_node = nullptr;
        return IsValidBST(root, prev_node);
    }
};
