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
int preorder(TreeNode* root,int target){
    if(root==NULL)return 1;
    if(root->val!=target)return -1;
    int l=preorder(root->left,target);
   int r= preorder(root->right,target);
   if(l==-1||r==-1)return -1;
   else return 1;
}


    bool isUnivalTree(TreeNode* root) {
          int target=root->val;
        int ans=  preorder(root,target); 
        
        
        if(ans==-1)return false;
        else return true;
           }
};