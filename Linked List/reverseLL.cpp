//Leetcode 206. Reverse Linked List

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class BruteSolution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* temp = head;
        stack<int> st;
        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;

        while(temp!=NULL){
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};

class BetterSolution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;


        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
            if(head == NULL || head->next == NULL){
                return head;
            }

            ListNode* newhead = reverseList(head->next);
            ListNode* front = head->next;
            front->next = head;
            head->next= NULL;
        return newhead;
    }
};