//Leetcode 84. Largest Rectangle in Histogram

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int maxA = 0;
        for(int i=0; i<=n; i++) {
            while( !st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
            
                int width = st.empty() ? i : i - st.top() - 1;

                maxA = max(maxA, width * height); 
            }
            st.push(i);
        }
        return maxA;
    }
};