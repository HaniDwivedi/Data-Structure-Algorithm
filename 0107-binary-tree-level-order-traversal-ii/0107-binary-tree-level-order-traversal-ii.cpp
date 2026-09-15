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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            // 1. Capture the exact number of nodes at the current level
            int size = q.size(); 
            vector<int> temp;
            
            // 2. Process all nodes belonging to this level
            for (int i = 0; i < size; i++) {
                TreeNode* t = q.front();
                q.pop();
                
                // Store the node's integer value
                temp.push_back(t->val);
                
                // Push children to the queue for the next level
                if (t->left != nullptr) q.push(t->left);
                if (t->right != nullptr) q.push(t->right);
            }
            
            // 3. Add the complete level to our answers
            ans.push_back(temp);
        }
        
        // 4. Reverse to get bottom-up order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
