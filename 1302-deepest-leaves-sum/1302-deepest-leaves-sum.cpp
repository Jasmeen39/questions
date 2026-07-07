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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int levelsum;
        while(!qu.empty()){
            levelsum=0;
            int curr_size=qu.size();
            for(int i=0; i<curr_size;i++){
                TreeNode* curr_node=qu.front();
                qu.pop();
                levelsum+=curr_node->val;
                if(curr_node->left!=NULL) qu.push(curr_node->left);
                if(curr_node->right!=NULL) qu.push(curr_node->right);
            }
        }
        return levelsum;
    }
};