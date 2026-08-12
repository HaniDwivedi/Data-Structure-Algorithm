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

  void traverse(TreeNode* node,vector<int
  >&res){if (!node) return;
   res.push_back(node->val);    // Root
        traverse(node->left, res);  // Left
       
        traverse(node->right, res); // Right

  }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        traverse(root,res);
        return res;

    }
};