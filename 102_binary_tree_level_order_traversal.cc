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
    void Preorder(TreeNode* root, int depth, std::vector<std::vector<int>>& nodes_by_level){
        if(root == nullptr)
            return;
        if(depth == nodes_by_level.size())
            nodes_by_level.push_back({root -> val});
        else
            nodes_by_level[depth].push_back(root -> val);
        Preorder(root -> left, depth + 1, nodes_by_level);
        Preorder(root -> right, depth + 1, nodes_by_level);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> nodes_by_level;
        Preorder(root, 0, nodes_by_level);
        return nodes_by_level;
    }
};
