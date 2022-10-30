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
    struct DpValues{
        int overall_best_distance;
        int root_best_distance;
        DpValues(): overall_best_distance(INT_MIN), root_best_distance(INT_MIN) {}
        DpValues(int overall_best_distance, int root_best_distance): overall_best_distance(overall_best_distance), root_best_distance(root_best_distance) {}
    };
    DpValues* BestMaxPath(TreeNode* root){
        if(root == nullptr)
            return new DpValues();
        DpValues* right_dp = BestMaxPath(root -> right);
        DpValues* left_dp = BestMaxPath(root -> left);
        DpValues* cur_dp = new DpValues(INT_MIN, root -> val);
        if(std::max(right_dp -> root_best_distance, left_dp -> root_best_distance) > 0)
            cur_dp -> root_best_distance += std::max(right_dp -> root_best_distance, left_dp -> root_best_distance);
        cur_dp -> overall_best_distance = root -> val;
        if(right_dp -> root_best_distance > 0)
            cur_dp -> overall_best_distance += right_dp -> root_best_distance;
        if(left_dp -> root_best_distance > 0)
            cur_dp -> overall_best_distance += left_dp -> root_best_distance;
        cur_dp -> overall_best_distance = std::max(cur_dp -> overall_best_distance, std::max(right_dp -> overall_best_distance, left_dp -> overall_best_distance));
        return cur_dp;
    }
    int maxPathSum(TreeNode* root) {
        return BestMaxPath(root) -> overall_best_distance;
    }
};
