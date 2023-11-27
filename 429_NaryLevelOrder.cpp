"""
Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]
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
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
  
        // Empty node return
        if(root==NULL)
           return res;
        
        // Using queue for level order traversal
        queue<Node*> q;
        q.push(root);
        // BFS
        while(!q.empty())
        {
            int s = q.size();
            vector<int> temp;
            for(int i=0; i<s; i++)
            {
                Node *curr = q.front();
                q.pop();
                temp.push_back(curr->val);  
                for(auto it = curr->children.begin(); it!=curr->children.end(); it++)
                {
                q.push(*it);
                }
            }   
        res.push_back(temp);
        }
        
        return res;
    }
};