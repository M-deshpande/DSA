//Leetcode 496. Next Greater Element I

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        int ansSize=nums1.size();
        map<int,int> mp;
        for(int i=0;i<ansSize;i++){
            mp[nums1[i]]=i;
        }
        vector<int> nge(ansSize);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            int ele=nums2[i];
            while(!st.empty() && st.top()<ele){
                st.pop();
            }
            int greaterElement;
            if(st.empty()){
                greaterElement=-1;
            }
            else{
                greaterElement=st.top();
            }

            if(mp.find(ele)!=mp.end()){
                nge[mp[ele]]=greaterElement;
            }
            st.push(ele);
        }
        return nge;
    }
};