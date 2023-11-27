"""
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
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
    bool isIdent(TreeNode *r, TreeNode *s)
    {
        if(!r && !s)
            return true;
        if(!r || !s)
            return false;
        if(r->val!=s->val)
            return false;
        return isIdent(r->left, s->left) && isIdent(r->right,s->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        if(isIdent(root, subRoot))
            return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
};