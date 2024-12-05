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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto fr = q.front();
            TreeNode* f = fr.first;
            auto cod = fr.second;
            q.pop();
            mp[cod.second][cod.first].insert(f->val);
            if (f->left) {
                q.push({f->left, {cod.first + 1, cod.second - 1}});
            }
            if (f->right) {
                q.push({f->right, {cod.first + 1, cod.second + 1}});
            }
        }

        for (auto it : mp) {
            auto& colMap = it.second;
            vector<int> a;
            for (auto i : colMap) {
                auto mset = i.second;
                a.insert(a.end(), mset.begin(), mset.end());
            }
            ans.push_back(a);
        }
        return ans;
    }
};