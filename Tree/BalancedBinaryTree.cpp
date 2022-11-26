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
    bool isBalanced(TreeNode* root) {
        if (root==nullptr) return true;
        int balancedDepth = checkDepth(root);
        if (balancedDepth==-1) return false;
        else return true;
    }
    
    int checkDepth(TreeNode* root) {
        if (root==nullptr) return 0;
        
        int leftDepth = checkDepth(root->left);
        int rightDepth = checkDepth(root->right);
        
        if (abs(leftDepth-rightDepth)>1 || leftDepth==-1 || rightDepth==-1) return -1;
        return max(leftDepth, rightDepth)+1;
        
    }
};
