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
    int maxdiff=-1;
    void checkdiff(TreeNode* root,TreeNode *child){
        if(root==NULL) return;
        if(child) {maxdiff=max(maxdiff,abs((root->val)-(child->val)));
        checkdiff(root,child->left);
        checkdiff(root,child->right);
        }
    }
    void checkroot(TreeNode* root){
        if(root==NULL) return;
        checkdiff(root, root->left);
        checkdiff(root, root->right);
        
        checkroot(root->left);
        checkroot(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL) return 0;
        checkroot(root);
        return maxdiff;
    }
};