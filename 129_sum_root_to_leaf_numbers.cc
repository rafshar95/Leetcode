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
    int Postorder(TreeNode* root, int parent_value){
        if(root == nullptr)
            return 0;
        if(root -> left == nullptr && root -> right == nullptr)
            return parent_value * 10 + root -> val;
        return Postorder(root -> right, parent_value * 10 + root -> val) + Postorder(root -> left, parent_value * 10 + root -> val);
    }
    int sumNumbers(TreeNode* root) {
        return Postorder(root, 0);
    }
};
