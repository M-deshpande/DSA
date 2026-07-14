//Leetcode 2149. Rearrange Array Elements by Sign

#include <bits/stdc++.h>
using namespace std;

class BruteSolution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>pos, neg;
        for(int i=0; i<n; i++){
            if(nums[i] > 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }

        for(int i=0; i<n/2; i++){
            nums[i*2] = pos[i];
            nums[i*2+1] = neg[i];
        }
        return nums;
    }
};


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int posInd = 0, negInd = 1;
        for(int i=0; i<n; i++){
            if(nums[i] > 0) {
                ans[posInd] = nums[i];
                posInd += 2;
            }
            else {
                ans[negInd] = nums[i];
                negInd +=2;
            }
        }
        return ans;
    }
};