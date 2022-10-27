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
    void FindPaths(TreeNode* root, const int target_sum, std::unordered_map<TreeNode*, std::vector<std::vector<int>>>& paths){
        if(root == nullptr)
            return;
        if(root -> left == nullptr && root -> right == nullptr){
            if(target_sum == root -> val)
                paths[root] = {{root -> val}};
            else
                paths[root] = {};
            return;
        }
        FindPaths(root -> left, target_sum - root -> val, paths);
        FindPaths(root -> right, target_sum - root -> val, paths);
        paths[root] = {};
        if(paths.find(root -> left) != paths.end()){
            for(int i = 0; i < paths[root -> left].size(); i++){
                paths[root].push_back({root -> val});
                paths[root].back().insert(paths[root].back().end(), paths[root -> left][i].begin(), paths[root -> left][i].end());
            }
        }
        if(paths.find(root -> right) != paths.end()){
            for(int i = 0; i < paths[root -> right].size(); i++){
                paths[root].push_back({root -> val});
                paths[root].back().insert(paths[root].back().end(), paths[root -> right][i].begin(), paths[root -> right][i].end());
            }
        }

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::unordered_map<TreeNode*, std::vector<vector<int>>> paths;
        FindPaths(root, targetSum, paths);
        if(root == nullptr)
            return {};
        return paths[root];
    }
};
