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
public:int flag=0;
void preorder(TreeNode* root,int target){
    if(root==NULL)return ;
    if(root->val!=target)flag=1;
    preorder(root->left,target);
  preorder(root->right,target);
 
}


    bool isUnivalTree(TreeNode* root) {
          int target=root->val;
      preorder(root,target); 
        
        
        if(flag==1)return false;
        else return true;
           }
};