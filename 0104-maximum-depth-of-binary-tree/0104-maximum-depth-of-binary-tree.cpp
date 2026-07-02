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
class Solution{
public:
    void maxd(TreeNode* root, int & maxdep,int & tempdep){
        if(root==NULL) return;
        tempdep++;
        maxdep=max(maxdep,tempdep);
        maxd(root->left,maxdep,tempdep);
        maxd(root->right,maxdep,tempdep);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        // int maxdep=0;
        // int tempdep=0;
        int leftdep=maxDepth(root->left);
        int rightdep=maxDepth(root->right);
        //maxd(root,maxdep,tempdep);
        return max(leftdep,rightdep)+1;
    }
};