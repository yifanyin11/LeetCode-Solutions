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
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr){
            return true;
        }
        return checkSym(root->left, root->right);
    }
    
    bool checkSym(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode==nullptr && rightNode==nullptr){
            return true;
        }
        if (leftNode==nullptr || rightNode==nullptr){
            return false;
        }
        if (leftNode->val != rightNode->val){
            return false;
        }     
        
        return checkSym(leftNode->right, rightNode->left) && checkSym(rightNode->right, leftNode->left);
    }
};

