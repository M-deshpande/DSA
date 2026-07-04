//Leetcode 110. Balanced Binary Tree

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
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;

        int leftHt = dfs(root -> left);
        if(leftHt == -1) return -1;
        int rightHt = dfs(root -> right);
        if(rightHt == -1) return -1;

        if(abs(leftHt - rightHt) > 1) return -1;

        return 1 + max(leftHt , rightHt);
    }
};