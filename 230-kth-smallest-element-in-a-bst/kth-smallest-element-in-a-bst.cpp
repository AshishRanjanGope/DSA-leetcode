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
    void DFS(TreeNode* root, vector<int>& value) {
        if (root == NULL)
            return;

        DFS(root->left, value);
        value.push_back(root->val);
        DFS(root->right, value);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> val;
        DFS(root, val);
        nth_element(val.begin(), val.begin() + k - 1, val.end());

        int x = val[k - 1];
        return x;
    }
};
