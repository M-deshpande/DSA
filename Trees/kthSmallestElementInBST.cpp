//Leetcode 230. Kth Smallest Element in a BST

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void inorder(TreeNode* root , vector<int>& values){
        // TreeNode* root = root;
        if(root){
            inorder(root->left, values);
            values.push_back(root->val);
            inorder(root->right, values);
        } 
    }

    int kthSmallest(TreeNode* root, int k) {
        if(!root) return NULL;
        vector<int>values;
        inorder( root, values );

        return values[k-1];
    }
};