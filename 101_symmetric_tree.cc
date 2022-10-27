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
    bool IsSymmetric(TreeNode* left_cur, TreeNode* right_cur){
        if((left_cur == nullptr) ^ (right_cur == nullptr))
            return false;
        if(left_cur == nullptr && right_cur == nullptr)
            return true;
        if(left_cur -> val != right_cur -> val)
            return false;
        if(!IsSymmetric(left_cur -> left, right_cur -> right) || !IsSymmetric(left_cur -> right, right_cur -> left))
            return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return IsSymmetric(root -> left, root -> right);
    }
};
