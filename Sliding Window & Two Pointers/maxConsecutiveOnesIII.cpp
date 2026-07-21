//Leetcode 1004. Max Consecutive Ones III

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;
        int zeros = 0;
        int l = 0, r = 0;
        while(r < n){
            if(nums[r] == 0) zeros++;

            if(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }

            if(zeros <= k){
                maxlen = max(maxlen , r - l + 1);
            }

            r++;
        }
        return maxlen;
    }
};