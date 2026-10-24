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
    bool isidentical(TreeNode* root,TreeNode* subroot){
        if (root==NULL || subroot==NULL) return root==subroot;
        return root->val==subroot->val && isidentical(root->left,subroot->left) && isidentical(root->right,subroot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if (root==NULL || subroot==NULL) return root==subroot;
        if(root->val==subroot->val && isidentical(root,subroot)) return true;
        return isSubtree(root->left,subroot)||isSubtree(root->right,subroot);
        
    }
};