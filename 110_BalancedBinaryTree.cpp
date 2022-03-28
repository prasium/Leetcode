"""
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

    a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
Input: root = [3,9,20,null,null,15,7]
Output: true
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
    int helper(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        else 
            return 1+ max(helper(root->left),helper(root->right));
        
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int left = helper(root->left);
        int right = helper(root->right);
        int diff = abs(left-right);
        return diff<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};

