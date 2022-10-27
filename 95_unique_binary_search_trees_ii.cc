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
    vector<TreeNode*> generateTrees(int n) {
        //std::vector<std::vector<std::vector<TreeNode*>>> unique_bst(n + 1, std::vector<std::vector<TreeNode*>> (n + 1));
        std::vector<TreeNode*> unique_bst[10][10];

        for(int dis = 0; dis <= n - 1; dis++)
            for(int first_value = 1; first_value + dis <= n; first_value++){
                int last_value = first_value + dis;
                for(int i = first_value; i <= last_value; i++){
                    if(i == first_value && i == last_value){
                        TreeNode* root = new TreeNode(i);
                        unique_bst[first_value][last_value].push_back(root);
                    }
                    else if(i == first_value){

                        for(int j = 0; j < unique_bst[i + 1][last_value].size(); j++){
                            TreeNode* root = new TreeNode(i);
                            root -> right = unique_bst[i + 1][last_value][j];
                            unique_bst[first_value][last_value].push_back(root);
                        }
                    }
                    else if(i == last_value){
                        for(int j = 0; j < unique_bst[first_value][i - 1].size(); j++){
                            TreeNode* root = new TreeNode(i);
                            root -> left = unique_bst[first_value][i - 1][j];
                            root -> right = nullptr;
                            unique_bst[first_value][last_value].push_back(root);
                        }
                    }
                    else{
                        for(int j = 0; j < unique_bst[first_value][i - 1].size(); j++)
                            for(int l = 0; l < unique_bst[i + 1][last_value].size(); l++){
                                TreeNode* root = new TreeNode(i);
                                root -> left = unique_bst[first_value][i - 1][j];
                                root -> right = unique_bst[i + 1][last_value][l];
                                unique_bst[first_value][last_value].push_back(root);
                            }
                    }
                }
             }
        return unique_bst[1][n];
    }
};
