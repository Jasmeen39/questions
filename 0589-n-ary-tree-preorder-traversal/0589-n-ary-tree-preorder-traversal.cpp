/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;
                    //Recursion
    void prehelper(Node* root){
        if(root==NULL) return;
        res.push_back(root->val);
        for( auto child: root->children){
            prehelper(child);
        }
    }
    vector<int> preorder(Node* root) {
        if(root==NULL) return res;
        //prehelper(root);
                   //Iterative
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* curr=st.top();
            res.push_back(st.top()->val);
            st.pop();
            //Insert in reverse because we want the left most at top
            for(int i=curr->children.size()-1;i>=0;i--){
                st.push(curr->children[i]);
            }
        }
        return res;
    }
};