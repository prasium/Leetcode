"""
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.
"""
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
    
    void inOrderTrav(TreeNode *r, vector<TreeNode *> &v)
    {
        if(r==NULL)
            return ;
        inOrderTrav(r->left,v);
        v.push_back(r);
        inOrderTrav(r->right,v);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
     TreeNode *head = new TreeNode(0);
     vector<TreeNode*> v;
     inOrderTrav(root,v);
        TreeNode *temp=head;
        for(auto it=v.begin();it!=v.end();it++)
        {
           temp->right= new TreeNode((*it)->val);
            temp=temp->right;
        }
        return head->right;
    }
};