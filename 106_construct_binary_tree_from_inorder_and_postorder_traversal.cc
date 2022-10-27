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
    TreeNode* BuildTree(std::vector<int>& inorder, std::vector<int>& postorder, int inorder_start_index, int inorder_finish_index, int postorder_start_index, int postorder_finish_index){
        if(postorder_start_index > postorder_finish_index)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[postorder_finish_index]);
        int left_subtree_size = 0;
        for(int i = inorder_start_index; inorder[i] != root -> val; i++){
            left_subtree_size++;
        }
        root -> left = BuildTree(inorder, postorder, inorder_start_index, inorder_start_index + left_subtree_size - 1, postorder_start_index, postorder_start_index + left_subtree_size - 1);
        root -> right = BuildTree(inorder, postorder, inorder_start_index + left_subtree_size + 1, inorder_finish_index, postorder_start_index + left_subtree_size, postorder_finish_index - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return BuildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
