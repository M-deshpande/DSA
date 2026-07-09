#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size(); 
        vector<int> ans(n);
        
        stack<int> st;   
        for(int i=2*n-1; i>=0; i--){
            int ind = i % n;
            
            int currEl = arr[ind];
            while(!st.empty() && st.top() <= currEl) {
                st.pop();
            }
            
            if(i < n) {
                
                if(st.empty()) ans[i] = -1;
                    
               
                else  ans[i] = st.top();
            }
            
            st.push(currEl);
        }
        return ans;
    }
};