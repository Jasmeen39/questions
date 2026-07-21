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
                        //Brute
    //This will get that fixed root one by one and check diff with it's different children.
    void checkdiff(TreeNode* root,TreeNode *child){
        if(root==NULL) return;
        if(child) {maxdiff=max(maxdiff,abs((root->val)-(child->val)));
        checkdiff(root,child->left);
        checkdiff(root,child->right);
        }
    }
    //This will take the different roots one by one
    void checkroot(TreeNode* root){
        if(root==NULL) return;
        checkdiff(root, root->left);
        checkdiff(root, root->right);
        
        checkroot(root->left);
        checkroot(root->right);
    }
                     //Optimal
    int findmaxdiff(TreeNode* root, int minval, int maxval){
        if (root==NULL) return abs(minval-maxval);
        minval=min(minval,root->val);
        maxval=max(maxval,root->val);
        int l= findmaxdiff(root->left, minval, maxval);
        int r= findmaxdiff(root->right, minval, maxval);
        return max(l,r);
    }                 

    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL) return 0;
        //checkroot(root);
        maxdiff=findmaxdiff(root,root->val,root->val);
        return maxdiff;
    }
};