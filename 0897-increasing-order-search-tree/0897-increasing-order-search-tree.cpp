class Solution {
private:
    TreeNode* current;

    void Inorder(TreeNode* root) {
        if (root == nullptr) return;

        Inorder(root->left);

        current->right = root;
        root->left = nullptr; 
        current = root;       

        Inorder(root->right);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        current = dummy;

        Inorder(root);

        return dummy->right;
    }
};