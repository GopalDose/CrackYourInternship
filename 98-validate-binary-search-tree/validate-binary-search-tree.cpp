/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root, long long int lb, long long int ub) {
        if (root == NULL)
            return true;
        if ((lb < root->val && ub > root->val) && solve(root->left, lb, root->val) &&
            solve(root->right, root->val, ub)) {
            return true;
        } else
            return false;
    }
    bool isValidBST(TreeNode* root) {
        long long int LB = -4294967296;
        long long int UB = 4294967296;
        bool ans = solve(root, LB, UB);
        return ans;
    }
};