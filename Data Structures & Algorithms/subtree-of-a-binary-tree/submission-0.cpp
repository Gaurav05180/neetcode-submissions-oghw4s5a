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

    bool is_sub_tree = false;

    bool isSubTree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;

        return root->val == subRoot->val && isSubTree(root->left, subRoot->left) && isSubTree(root->right, subRoot->right);
    }

    void preorder(TreeNode* root, TreeNode* subRoot){
        if(!root) return;

        if(isSubTree(root, subRoot)) {
            is_sub_tree = true;
            return;
        }

        preorder(root->left, subRoot);
        preorder(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        preorder(root, subRoot);

        return is_sub_tree;
    }
};
