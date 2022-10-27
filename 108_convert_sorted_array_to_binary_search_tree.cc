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
    TreeNode* SortedArrayToBST(std::vector<int>& nums, int start_index, int finish_index){
        if(start_index > finish_index)
            return nullptr;
        int mid_index = (start_index + finish_index) / 2;
        TreeNode* root = new TreeNode(nums[mid_index]);
        root -> right = SortedArrayToBST(nums, mid_index + 1, finish_index);
        root -> left = SortedArrayToBST(nums, start_index, mid_index - 1);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return SortedArrayToBST(nums, 0, nums.size() - 1);
    }
};
