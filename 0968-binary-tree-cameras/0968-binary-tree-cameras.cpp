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
int dfs(TreeNode* root,int &camera){
    if(root==NULL)return 2; 
    int l = dfs(root->left,camera);
    int r =dfs(root->right,camera);
    if(l==0||r==0){camera++;return 1; }
    if(l==1||r==1)return 2 ;
    
    return 0 ;
}    
public:
    int minCameraCover(TreeNode* root) {
       int camera=0; 
        if (dfs(root,camera)==0)camera++;
        return camera ; 
    }
};