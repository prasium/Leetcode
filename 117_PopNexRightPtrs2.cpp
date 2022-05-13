"""
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
"""
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        // Queue for Level order traversal
        queue<Node *> q;
        q.push(root);
        // Level Order traversal
        while(!q.empty())
        {
            int s = q.size();
             // ptr to keep track of right most node
            Node *nexRight;
            // traverse level wise
            for(int i = 0, count=0; i<s; i++, count++)
            {
                Node *temp = q.front();
                q.pop();
                //Excluding Right most nodes as they must point to NULL, storing them in nexRight ptr 
                if(count==0)
                {
                    nexRight = temp;
                }
                // for left branch nodes now they must point to their right most next nodes
                if(count>0)
                {
                    temp->next = nexRight;
                    // make current node for that level as next right candidate
                    nexRight = temp;
                }
           
                // Reverse level order traversal, insert right leaf first then left
                if(temp->right)
                    q.push(temp->right);
                if(temp->left)
                    q.push(temp->left);
                }
        }
        return root;
    }
};