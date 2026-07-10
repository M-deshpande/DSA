//Leetcode 42. Trapping Rain Water

#include <bits/stdc++.h>
using namespace std;

// class bruteSolution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         if(n == 0) return 0;

//         vector<int> left(n), right(n);

//         left[0] = height[0];
//         for(int i = 1; i < n; i++){
//             left[i] = max(height[i], left[i-1]);
//         }

//         right[n-1] = height[n-1];
//         for(int i = n-2; i >= 0; i--){
//             right[i] = max(height[i], right[i+1]);
//         }

//         int total = 0;

//         for(int i = 0; i < n; i++){
//             total += min(left[i], right[i]) - height[i];
//         }

//         return total;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int left = 0;
        int right = n-1;

        int leftmax = 0, rightmax = 0;
        int total = 0;

        while(left <= right){
            if(height[left] <= height[right]){
                if( height[left] > leftmax ){
                    leftmax = height[left];
                }
                else {
                    total += leftmax - height[left];
                }
                left++;
            }

            else {
                if( height[right] > rightmax ){
                    rightmax = height[right];
                }
                else {
                    total += rightmax - height[right];
                }
                right--;
            }
        }
        return total;
    }
};