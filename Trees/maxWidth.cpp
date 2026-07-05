//Leetcode 662. Maximum Width of Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        using ull = unsigned long long;
        queue<pair<TreeNode*, ull>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            ull mmin = it.second;
            int size = q.size();
            ull first, last;
            for(int i=0; i<size; i++){
                ull cur_id = q.front().second- mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if(i==0) first = cur_id;
                if(i==size-1) last = cur_id;

                if(node->left) q.push({node->left, cur_id*2+1});
                if(node->right) q.push({node->right, cur_id*2+2});
            }
            ans = max(ans, (int)(last-first+1));
        }
        return ans;
    }
};