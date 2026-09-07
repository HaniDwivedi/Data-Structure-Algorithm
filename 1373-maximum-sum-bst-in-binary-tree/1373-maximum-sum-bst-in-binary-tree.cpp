class Solution {
private:
    int max_sum = 0;

    struct NodeInfo {
        bool isBST;
        int min_val;
        int max_val;
        int sum;
    };

    NodeInfo solve(TreeNode* root) {
        if (!root) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        NodeInfo current;
//Agar aap normal local variable ya object banate ho (jaise NodeInfo left = solve(root->left);), tab wo stack par banta hai aur uske fields ko access karne ke liye dot (.) operator use hota hai.


       if (left.isBST && right.isBST && root->val > left.max_val && root->val < right.min_val) {
            current.isBST = true;
            current.min_val = min(root->val, left.min_val);
            current.max_val = max(root->val, right.max_val);
            current.sum = left.sum + right.sum + root->val;
            
            max_sum = max(max_sum, current.sum);
        } else {
            current.isBST = false;
        }

        return current;
    }

public:
    int maxSumBST(TreeNode* root) {
        max_sum = 0;
        solve(root);
        return max_sum;
    }
};