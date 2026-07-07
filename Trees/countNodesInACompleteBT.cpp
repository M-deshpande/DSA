//Leetcode 222. Count Complete Tree Nodes

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
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int findLeftHeight = leftHeight(root);
        int findRightHeight = rightHeight( root);

        if( findLeftHeight == findRightHeight) return (1 << findLeftHeight) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int leftHeight( TreeNode*node){
        int hght = 0;
        while(node){
            node = node->left;
            hght++;
        }
        return hght;
    }

    int rightHeight( TreeNode*node){
        int hght = 0;
        while(node){
            node = node->right;
            hght++;
        }
        return hght;
    }
};