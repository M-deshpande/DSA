//Leetcode 98. Validate Binary Search Tree

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
    bool isValidBST(TreeNode* root) {
        return isValid( root, LONG_MIN, LONG_MAX);
    }

    bool isValid( TreeNode* root, long long minVal, long long maxVal){
        if(!root) return true;

        if(root->val >= maxVal || root->val <= minVal) return false;
        return isValid(root->left, minVal, root->val) &&
        isValid(root->right, root->val, maxVal);
    }
};