"""
Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value

Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
"""
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
    void preTrav(Node *r, vector<int> &res)
    {
        // Node empty return
        if(r==NULL)
            return;
        // Push in result vector current value
            res.push_back(r->val);
        // Recurse N-ary of current node 
        for(auto c : r->children)
        {
            preTrav(c, res);
        }
    }
    vector<int> preorder(Node* root) {
       vector<int> res;
        // Preorder traversal
        preTrav(root, res);
        return res;
    }
};