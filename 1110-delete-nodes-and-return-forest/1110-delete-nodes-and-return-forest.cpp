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
    //Postorder left right root
    TreeNode* dfs(TreeNode* root, unordered_set<int>& to_delete, vector<TreeNode*> &forest){
        if(root==NULL) return NULL;
        //Process children first
        root->left=dfs(root->left,to_delete,forest);
        root->right=dfs(root->right,to_delete,forest);
        //If root doesnt needs to be deleted return it's address
        if(to_delete.find(root->val)==to_delete.end()){
            return root;
        }
        //If root needs to be deleted and it's children are not NULL
        if(root->left!=NULL){
            forest.push_back(root->left);
        }
        if(root->right!=NULL){
            forest.push_back(root->right);
        }
        //Delete every relation that root, it's fine even if you dont do so
        root->left=NULL;
        root->right=NULL;
        return NULL; //In the place of deleted node we will write NULL
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> set;
        for(auto x: to_delete){
            set.insert(x);
        }
        vector<TreeNode*> forest;
        root=dfs(root,set,forest);
        //If original root is not deleted push that one too
        if(root!=NULL){
            forest.push_back(root);
        }
        return forest;
    }
};