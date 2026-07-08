//Leetcode 230. Ceil in BST

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ceil = -1;
        while(root){
            if(root->data == x){
                ceil = root->data ;
                return ceil;
            }
            else if(root->data< x){
                root = root->right;
            }
            else {
                ceil = root->data;
                root = root->left;
            }
        }
        return ceil;
    }
};
