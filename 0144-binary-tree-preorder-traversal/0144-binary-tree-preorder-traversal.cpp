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
               //Recursion
    // void traversal(TreeNode* root,vector<int>& ans){
    //     if(root==NULL) return;
    //     ans.push_back(root->val);
    //     traversal(root->left,ans);
    //     traversal(root->right,ans);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // traversal(root,ans);
        // return ans;
              //Iterative
        stack<TreeNode*> st;
        TreeNode* curr=root;
        vector<int> res;
        while(curr!=NULL or !st.empty()){
            if(curr!=NULL){
                res.push_back(curr->val);
                st.push(curr->right);
                curr=curr->left;
            }
            else{
                curr=st.top();
                st.pop();
            }
        }
        return res;
    }
};