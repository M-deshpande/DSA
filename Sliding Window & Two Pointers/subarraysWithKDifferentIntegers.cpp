//Leetcode 992. Subarrays with K Different Integers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    int atMost(vector<int>& nums, int k) {
        if(k < 0) return 0;

        map<int , int>mpp;
        int cnt = 0;
        int r = 0, l = 0;
        while(r < nums.size()){
            mpp[nums[r]]++;

            while(mpp.size() > k){
                mpp[nums[l]]--;

                if(mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                
                l++;
            }

            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
};