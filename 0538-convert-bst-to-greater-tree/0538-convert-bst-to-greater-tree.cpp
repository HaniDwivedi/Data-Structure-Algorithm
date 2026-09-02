class Solution {
public:
    void solve(TreeNode* root, int &ans) {
        if (root == nullptr) return;
        
        // Traverse right subtree first (greater values)
        solve(root->right, ans);
        
        // Update sum and node value
        ans += root->val;
        root->val = ans;
        
        // Traverse left subtree
        solve(root->left, ans);
    }

    TreeNode* convertBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return root;
    }
};