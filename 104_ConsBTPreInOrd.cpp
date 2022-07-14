"""
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
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
    int preOrdInd;
    unordered_map<int, int> mapInOrd;
    TreeNode* daq(vector<int> &preorder, int left, int right)
    {
        if(left<=right)
        {
         int rootVal = preorder[preOrdInd++];
            TreeNode *root = new TreeNode(rootVal);
            
            root->left = daq(preorder, left, mapInOrd[rootVal]-1);
            root->right = daq(preorder, mapInOrd[rootVal]+1, right);
            return root;
        }
        return NULL;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preOrdInd = 0;
        for(int i=0; i<inorder.size(); i++)
        {
            mapInOrd[inorder[i]]= i;
        }  
        
        return daq(preorder, 0, preorder.size()-1);
    }
};