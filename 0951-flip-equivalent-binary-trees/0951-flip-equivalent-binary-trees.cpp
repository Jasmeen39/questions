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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        //The difference between this and int=verted is inverted we need to flip every node but in this question we may or may not need to flip
        if(root1==NULL && root2==NULL ) return true;
        if(root1==NULL || root2==NULL ) return false;
        if(root1->val!=root2->val ) return false;
        return
        //A=Dont flip 
        (
            flipEquiv(root1->left,root2->left)
            &&
            flipEquiv(root1->right,root2->right)
        )
        ||
        //B=Flip
        (
            flipEquiv(root1->left,root2->right)
            &&
            flipEquiv(root1->right,root2->left)
        );
    }
};