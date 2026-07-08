//Leetcode 235. Lowest Common Ancestor of a Binary Search Tree

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build( preorder, i, INT_MAX);
    }
    TreeNode* build(vector<int>& preorder, int& i, int bound){
        if(preorder.size() == i || preorder[i] > bound ) return NULL;

        TreeNode* root =  new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        int cur = root->val;
        if(cur< p->val && cur < q->val){
            return lowestCommonAncestor(root->right , p , q );
        }
        if(cur > p->val && cur > q->val){
            return lowestCommonAncestor(root-> left , p , q );
        }
        return root;
    }
};