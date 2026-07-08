//Leetcode 653. Two Sum IV - Input is a BST

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

class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse;

    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (!reverse)
            pushAll(node->right);
        else
            pushAll(node->left);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);

            if (!reverse)
                node = node->left;
            else
                node = node->right;
        }
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        // Create two iterators: one for smallest-to-largest order, another for largest-to-smallest
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        // Get first values from both ends
        int i = l.next();
        int j = r.next();

        // Loop until the two pointers meet
        while (i < j) {
            // If the two numbers add up to k, we found a pair
            if (i + j == k) return true;
            // If sum is too small, move left iterator forward
            else if (i + j < k) i = l.next();
            // If sum is too large, move right iterator backward
            else j = r.next();
        }

        // If no pair found, return false
        return false;
    }
};