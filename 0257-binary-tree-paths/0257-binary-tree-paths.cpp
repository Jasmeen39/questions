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
    vector<string> binaryTreePaths(TreeNode* root) {
        //a
        vector<string> ans;
        if(root==NULL) return ans;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(to_string(root->val));
            return ans;
        }
        //b
        vector<string> leftans=binaryTreePaths(root->left);
        vector<string> rightans=binaryTreePaths(root->right);
        //c
        for(string str:leftans){
            ans.push_back(to_string(root->val)+"->"+str);
        }
        for(string str:rightans){
            ans.push_back(to_string(root->val)+"->"+str);
        }
        return ans;
    }
};