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
    //Again ignore
    void invert(TreeNode* left,TreeNode* right){
        if(left==NULL ) return;
        if(right==NULL) return;
        //swap(invert(left->left->val,left->right->val),invert(right->right->val,right->left->val));
        int leftval=left->val;
        int rightval=right->val;
        swap(leftval,rightval);
        invert(left->left,right->right);
        invert(right->left,left->right);
    }
    TreeNode* invertTree(TreeNode* root) {
      if(root==NULL) return NULL;
      //invert(root->left,root->right);
      swap(root->left,root->right);
      //Chat gpt why not value? Hint: Children would still be in same place
      invertTree(root->left);
      invertTree(root->right);
      return root;  
    }
};