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
    TreeNode* BuildTree(std::vector<int>& preorder, std::vector<int>& inorder, int preorder_start, int preorder_end, int inorder_start, int inorder_end){
        if(preorder_start > preorder_end)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preorder_start]);
        int left_subtree_size = 0;
        for(int i = inorder_start; inorder[i] != root -> val; i++)
            left_subtree_size++;
        root -> left = BuildTree(preorder, inorder, preorder_start + 1, preorder_start + left_subtree_size, inorder_start, inorder_start + left_subtree_size - 1);
        root -> right = BuildTree(preorder, inorder, preorder_start + left_subtree_size + 1, preorder_end, inorder_start + left_subtree_size + 1, inorder_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return BuildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
