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
class Solution{
    public:
    bool getPathUtil(TreeNode* root, int B, vector<int>&arr){
        if(!root) return false;
        arr.push_back(root->val);
        if(root->val == B) return true;
        if(getPathUtil(root->left, B, arr) || getPathUtil(root->right, B, arr)) return true;
        arr.pop_back();
        return false;
    }
    vector<int> getPath(TreeNode* root, int B){
        vector<int>arr;
        if(!root) return arr;
        getPathUtil(root, B, arr);
        return arr;
    }
};