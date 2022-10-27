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
    void dfs(TreeNode* root, int depth, std::vector<std::vector<int>>& nodes_in_level){
        if(root == nullptr)
            return;
        if(nodes_in_level.size() == depth)
            nodes_in_level.push_back({root -> val});
        else
            nodes_in_level[depth].push_back(root -> val);
        dfs(root -> left, depth + 1, nodes_in_level);
        dfs(root -> right, depth + 1, nodes_in_level);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr)
            return {};
        std::vector<std::vector<int>> nodes_in_level;
        dfs(root, 0, nodes_in_level);
        std::reverse(nodes_in_level.begin(), nodes_in_level.end());
        return nodes_in_level;
    }
};
