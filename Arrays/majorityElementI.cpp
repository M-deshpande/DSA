//leetcode 169. Majority Element

#include <bits/stdc++.h>
using namespace std;

class bruteSolution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int cnt = 0;
            int val = nums[i];
            for(int j=0; j<n; j++){
                if(nums[j] == val)  cnt++;
            }
        if(cnt > n/2) return val;
        }
        return -1;
    }
};

class betterSolution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mpp;
        for(int i =0; i<n; i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            if(it.second > n/2) return it.first;
        }
    return -1;    
    }
};                       

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el;
        for(int i=0; i<nums.size(); i++){
            if(cnt == 0){
                cnt ++;
                el = nums[i];
            }

            else if(nums[i] == el){
                cnt ++;
            }

            else cnt --;
        }
        int cnt2;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == el) cnt2 ++;
        }
        if(cnt2 > nums.size() / 2) return el;
        return -1;
    }
};