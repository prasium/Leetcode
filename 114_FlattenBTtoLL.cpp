"""
Given the root of a binary tree, flatten the tree into a "linked list":

    The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.

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
    void flatten(TreeNode* root) {
         if( root )
        {
            //Move the left node to the right node
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode* node = root;
            
            //Move to the end of the prev left node which is the new right node
            while( node->right )
            {
                node = node->right;
            }
            
            //Append the right node to its end
            node->right = temp;
            flatten( root->right ); 
        } 
        return;
               
    }
};