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
    vector<int> postorder(Node* root) {
        vector<int> list;
        if(root==NULL){
            return list; 
        }
        help(list,root);
        list.push_back(root->val);
        return list;
    }

     void help(vector<int>& list,Node* root){
        vector<Node*> li;
        li = root->children;
        for(int i=0;i<li.size();i++){
            if(li[i]==NULL){
                continue;
            }
            help(list,li[i]);
            list.push_back(li[i]->val);
        }
    }
    
};