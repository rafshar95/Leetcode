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
    int dfs(TreeNode* root, bool& is_balanced){
        int left_height = (root -> left != nullptr) ? dfs(root -> left, is_balanced): -1;
        int right_height = (root -> right != nullptr) ? dfs(root -> right, is_balanced): -1;
        if(std::abs(right_height - left_height) > 1)
            is_balanced = false;
        return std::max(left_height, right_height) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool is_balanced = true;
        if(root == nullptr)
            return true;
        dfs(root, is_balanced);
        return is_balanced;
    }
};
