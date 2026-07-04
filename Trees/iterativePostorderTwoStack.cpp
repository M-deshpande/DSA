//Leetcode 145. Binary Tree Postorder Traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>s1, s2;
        vector<int>postorder;
        if(!root) return postorder;
        

        s1.push(root);
        while(!s1.empty()){
            root = s1.top();
            s1.pop();
            s2.push(root);

            if(root->left) s1.push(root->left);
            if(root->right) s1.push(root->right);
        }
        while(!s2.empty()){
            postorder.push_back(s2.top()->val);
            s2.pop();
        }
        return postorder;
    }
};