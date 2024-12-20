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
int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    return 1+max(left, right);
}
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int left = height(root->left);
        int right = height(root->right);
        int diff = abs(left-right);
        bool leftb = isBalanced(root->left);
        bool rightb = isBalanced(root->right);
        if(diff <= 1 && leftb && rightb) return true;
        return false; 
    }
};