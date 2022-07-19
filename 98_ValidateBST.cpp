"""
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

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
    
private:
    TreeNode *pre = NULL;
public:
        bool inOrder(TreeNode *root)
    {
        if(root==NULL)
            return true;
            
        if(!inOrder(root->left))
            return false;
            
        if(pre!=NULL && pre->val >=root->val)
            return false;
            
        pre=root;
        return inOrder(root->right);
       
    }

    bool isValidBST(TreeNode* root) {
        
        return inOrder(root);
    }
    
};