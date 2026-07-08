//GFG 

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {

        Node* pre = NULL;
        Node* suc = NULL;

        Node* temp = root;

        // Find Successor
        while(temp){
            if(key >= temp->data){
                temp = temp->right;
            }
            else{
                suc = temp;
                temp = temp->left;
            }
        }

        temp = root;

        // Find Predecessor
        while(temp){
            if(key <= temp->data){
                temp = temp->left;
            }
            else{
                pre = temp;
                temp = temp->right;
            }
        }

        return {pre, suc};
    }
};