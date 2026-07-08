//Leetcode 450. Delete Node in a BST

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};


class Solution {
public:

    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL)
            return root;

        return findLastRight(root->right);
    }

    TreeNode* helper(TreeNode* root) {
        // No left child
        if (root->left == NULL)
            return root->right;

        // No right child
        if (root->right == NULL)
            return root->left;

        // Both children exist
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);

        lastRight->right = rightChild;

        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL)
            return NULL;

        // If root itself is the node to delete
        if (root->val == key)
            return helper(root);

        TreeNode* dummy = root;

        while (root != NULL) {

            if (root->val > key) {

                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }
            else {

                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }
};