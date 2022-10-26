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
    void Traverse(TreeNode* root, std::vector<int>& ordered_values){
        if(root == nullptr)
            return;
        Traverse(root -> left, ordered_values);
        ordered_values.push_back(root -> val);
        Traverse(root -> right, ordered_values);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ordered_values;
        Traverse(root, ordered_values);
        return ordered_values;
    }
};
