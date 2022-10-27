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
    void PreorderTraversal(TreeNode* root, int depth, std::vector<std::vector<int>>& results){
        if(root == nullptr)
            return;
        if(results.size() == depth)
            results.push_back({root -> val});
        else
            results[depth].push_back(root -> val);
        PreorderTraversal(root -> left, depth + 1, results);
        PreorderTraversal(root -> right, depth + 1, results);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<vector<int>> results;
        PreorderTraversal(root, 0, results);
        for(int i = 1; i < results.size(); i += 2){
            std::reverse(results[i].begin(), results[i].end());
        }
        return results;
    }
};
