/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if(root==NULL||root==p||root==q)return root ;//now  you from l, r that something is coming 
    
    TreeNode* l = lowestCommonAncestor( root->left,  p,  q) ;
     TreeNode* r = lowestCommonAncestor( root->right,  p,  q) ;
    
    if(l!=NULL&&r!=NULL)return root;
    if(l!=NULL&&r==NULL)return l;
      if(r!=NULL&&l==NULL)return r;
TreeNode* n=NULL;
      return n;
    
    }
};