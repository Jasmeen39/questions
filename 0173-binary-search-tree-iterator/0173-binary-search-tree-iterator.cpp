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
class BSTIterator {
private:
stack<TreeNode*> mystack;
//Inorder= Left Node Right
//This will push the extreme left
void pushall(TreeNode* node){
    while(node!=NULL){
        mystack.push(node);
        node=node->left;
    }
}
public:
    //Give the root. And will push all its left. Baasically a constructor.
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    //This will give the next element and do other things as well (Most important)
    int next() {
       TreeNode* temp=mystack.top(); //Take to of the stack/ Smallest element/ node
       mystack.pop(); //Remove it
       pushall(temp->right); //If there's any right element push all it's extreme lefts/ Prepare next smallest
       return temp->val; //return the value.
    }
    //It will just tell if there is any next element.
    bool hasNext() {
        return !mystack.empty(); //If the stack is empty there is no next
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */