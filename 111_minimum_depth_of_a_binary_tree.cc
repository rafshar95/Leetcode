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
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int left_depth = minDepth(root -> left);
        int right_depth = minDepth(root -> right);
        return (std::min(left_depth, right_depth) == 0) ? std::max(left_depth, right_depth) + 1:  std::min(left_depth, right_depth) + 1;
    }
};
