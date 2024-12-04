/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        if(root->val == p->val) return root;
        if(root->val == q->val) return root; 

        if(l == NULL && r == NULL) return NULL;
        else if(l != NULL && r == NULL) return l;
        else if(l == NULL && r != NULL) return r;

        return root;
    }
};