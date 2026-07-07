#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; 

//conversion approach
class Solution {
  public:
    void reorder(Node *root) {
        // code here
        if(!root) return;
        int child = 0;
        if(root->left) child+=root->left->data;
        if(root->right) child+=root->right->data;
        if(child >= root->data) root->data = child;
        else{
            root->left->data = root->data;
            root->right->data = root->data;
        }
        
        reorder(root->left);
        reorder(root->right);
        
        int tot = 0;
        if(root->left) tot+=root->left->data;
        if(root->right) tot+= root->right->data;
        if(root->left || root->right) root->data = tot;
    }
};

//check sum property
class Solution {
public:
    bool isSumProperty(Node *root) {

        if(root == NULL)
            return true;

        // leaf node
        if(root->left == NULL && root->right == NULL)
            return true;

        int sum = 0;

        if(root->left)
            sum += root->left->data;

        if(root->right)
            sum += root->right->data;

        return (root->data == sum)
            && isSumProperty(root->left)
            && isSumProperty(root->right);
    }
};