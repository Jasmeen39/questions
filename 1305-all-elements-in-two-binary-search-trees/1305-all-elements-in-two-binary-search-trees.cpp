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
    void inordertraversal(TreeNode* root,vector<int> &vec){
        if(root){
            inordertraversal(root->left,vec);
            vec.push_back(root->val);
            inordertraversal(root->right,vec);
        }
    }
    void mergevector(vector<int> vec1,vector<int> vec2, vector<int> &res){
        int i,j,k;
        i=0; j=0; k=0;
        while(i<vec1.size() && j<vec2.size()){
            if(vec1[i]<vec2[j]){
                res[k]=vec1[i];
                i++;
                k++;
            }
            else{
                res[k]=vec2[j];
                j++;
                k++;
            }
        }
        while(i<vec1.size()){
            res[k]=vec1[i];
                i++;
                k++;
        }
        while(j<vec2.size()){
            res[k]=vec2[j];
                j++;
                k++;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1,tree2;
        inordertraversal(root1,tree1);
        inordertraversal(root2,tree2);
        vector<int> merged(tree1.size()+tree2.size());
        mergevector(tree1,tree2,merged);
        return merged;
    }
};