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

// By recursion

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        accessTree(root, res);
        return res;
    }
    
    void accessTree(TreeNode* root, vector<int> &res) {
        if (root==nullptr){
            return;
        }
        accessTree(root->left, res);
        res.push_back(root->val);
        accessTree(root->right, res);
    }
};

// By loop

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         accessTree(root, res);
//         return res;
//     }
    
//     void accessTree(TreeNode* root, vector<int> &res) {
//         if (root==nullptr){
//             return;
//         }
//         accessTree(root->left, res);
//         res.push_back(root->val);
//         accessTree(root->right, res);
//     }
// };
