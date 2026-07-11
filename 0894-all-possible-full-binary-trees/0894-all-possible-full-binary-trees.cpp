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
    vector<TreeNode*> solve(int n){
        if (n%2==0) return {};
        if(n==1) {
            TreeNode* root= new TreeNode(0);
            return {root};
        }
        vector<TreeNode*> res;
        for(int i=1; i<n; i+=2){
            vector<TreeNode*> leftallfbt=solve(i);
            vector<TreeNode*> rightallfbt=solve(n-i-1);
            for(auto l:leftallfbt){
                for(auto r:rightallfbt){
                    TreeNode* root= new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};