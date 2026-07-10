//Leetcode 85. Maximal Rectangle

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangle(vector<int>& height){
        int n = height.size();

        int maxA = 0;
        stack<int>st;
        for(int i=0; i<=n; i++){
            while (!st.empty() && (i == n || height[st.top()] >= height[i])){
                int ht = height[st.top()];
                st.pop();
                
                int width = st.empty() ? i : i - st.top() - 1;

                maxA = max(maxA, ht * width);
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);

        int maxA = 0;

        for (auto &row : matrix) {

            for (int i = 0; i < m; i++) {

                if (row[i] == '1')
                    height[i]++;
                else
                    height[i] = 0;
            }
            maxA = max(maxA, largestRectangle(height));
        }
        return maxA;
    }
};