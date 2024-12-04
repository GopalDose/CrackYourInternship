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
    void solve(TreeNode* root, int targetSum, vector<vector<int>>& ans,
               vector<int> path) {
        if (root == NULL)
            return;

        int curr = root->val;
        path.push_back(curr);
        if (root->left == NULL && root->right == NULL && targetSum-curr == 0) {
                ans.push_back(path);
            return;
        }
        solve(root->left, targetSum-curr, ans, path);
        solve(root->right, targetSum-curr, ans, path);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root, targetSum, ans, path);
        return ans;
    }
};