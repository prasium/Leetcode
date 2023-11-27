"""
Given the root of a binary tree, return the sum of values of its deepest leaves.

 Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
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
    // Get Maximum Depth
    int getMaxDepth(TreeNode *t)
    {
        if(t==NULL)
            return 0;
        int l = getMaxDepth(t->left);
        int r = getMaxDepth(t->right);
        return max(l,r)+1;
    }
    // Calculating sum of last level leaves
    void calSum(TreeNode *r, int &sum, int level)
    {
        if(r==NULL)
            return;
        queue<TreeNode*> q;
        q.push(r);
        // Starting root at 1st level
        int currLevel=1;
        // Level Order Traversal
        while(!q.empty())
        {
                  int s = q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                // Evaluate sum when its the max depth level
                if(currLevel==level)
                {
                    sum+=temp->val;
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            // Increment level
            currLevel++;
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        if(root==NULL)
            return sum;
        // store max depth first
        int depth= getMaxDepth(root);
        // then do bfs and get last level leaves sum
        calSum(root, sum, depth);
        return sum;
    }
};