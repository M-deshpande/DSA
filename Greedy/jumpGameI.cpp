//Leetcode 55. Jump Game

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxInd = 0;
        for(int i=0; i<nums.size(); i++){
            if(i > maxInd) return false;
            maxInd = max(maxInd, i + nums[i]);
        }
        return true;
    }   
};