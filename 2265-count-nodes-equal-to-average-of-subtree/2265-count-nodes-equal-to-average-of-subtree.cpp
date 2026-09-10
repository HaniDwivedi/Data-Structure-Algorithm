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
private:


pair<int,int> solve(TreeNode* root, int &total_node){
    if(root==NULL)return{ 0,0};
    int size=1;
    auto ls=solve(root->left,total_node );
    auto rs=solve(root->right,total_node);
   size+=ls.second;
    size+=rs.second;
    int sum = ls.first+rs.first+root->val;
    if((sum/size)==root->val)total_node++;
return {sum,size}; 
 

    


 }

public:
    int averageOfSubtree(TreeNode* root) {
        int total_nodes=0;solve(root,total_nodes);
        return total_nodes;
    }
};