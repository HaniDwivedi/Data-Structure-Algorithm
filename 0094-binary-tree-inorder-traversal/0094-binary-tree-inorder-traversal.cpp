class Solution {
public:
    // Helper function jo result vector ko reference se leta hai
    void traverse(TreeNode* node, vector<int>& result) {
        if (!node) return;

        traverse(node->left, result);  // Left
        result.push_back(node->val);    // Root
        traverse(node->right, result); // Right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        // Agar tree bada hai toh result.reserve(100); kar sakte hain
        traverse(root, result);
        return result;
    }
};