//Leetcode 863. All Nodes Distance K in Binary Tree

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
    void markparents(TreeNode* root, unordered_map<TreeNode* , TreeNode*>&parent_track){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            if(cur->left) {
                parent_track[cur->left] = cur;
                q.push(cur->left);
            }
            if(cur->right) {
                parent_track[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*>parent_track;
        markparents(root, parent_track);

        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int cur_level=0;
        while(!q.empty()){
            int size = q.size();
            if(cur_level++ == k) break;
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();

                if(cur->left && !visited[cur->left]) {
                    q.push(cur->left);
                    visited[cur->left] = true;
                }

                if(cur->right && !visited[cur->right]) {
                    q.push(cur->right);
                    visited[cur->right] = true;
                }   
                if(parent_track[cur] && !visited[parent_track[cur]]){
                    q.push(parent_track[cur]);
                    visited[parent_track[cur]] = true;
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            res.push_back(cur->val);
        }
        return res;
    }
};