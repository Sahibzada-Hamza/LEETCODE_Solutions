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
        if(root==NULL) return NULL;
        if(root==p ||root==q) return root;
        TreeNode* right_r=lowestCommonAncestor(root->right, p,q);
        TreeNode* left_r=lowestCommonAncestor(root->left, p,q);
        if(right_r==NULL && left_r==NULL) return NULL;
        else if(right_r!=NULL && left_r!=NULL)return root;
        else if(right_r!=NULL) return right_r;
        else return left_r; 
    }
};