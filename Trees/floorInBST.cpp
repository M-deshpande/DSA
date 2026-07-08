//Leetcode 230. Floor in BST

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 

class Solution {
  public:
    int findMaxFork(Node* root, int x) {
        // code here
        int floor = -1;
        while(root){
            if(root->data == x){
                floor = root->data ;
                return floor;
            }
            else if(root->data > x){
                root = root->left;
            }
            else {
                floor = root->data;
                root = root->right;
            }
        }
        return floor;
    }
};