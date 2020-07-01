/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
 */
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
    int sum=0;
    void backtrack(string temp, TreeNode* root)
    {
        if(root==NULL)
            return;
        
            temp+=to_string(root->val);
        if(root->left==NULL && root->right==NULL)
        {
         sum+=stoi(temp);
         temp.back();
        }
        backtrack(temp, root->left);
        backtrack(temp, root->right);
        
        
        
    }
    int sumNumbers(TreeNode* root) {
        
        backtrack("", root);
        return sum;
    }
};
