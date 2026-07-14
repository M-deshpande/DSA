//Leetcode 128. Longest Consecutive Sequence

#include <bits/stdc++.h>
using namespace std;

class BruteSolution {
public:
    bool ls(vector<int>& nums, int x, int n ){
        for(int i=0; i<n; i++){
            if(nums[i] == x){
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int longest = 0;
        for(int i=0; i<n; i++){
            int x = nums[i];
            cnt = 1;
            while(ls(nums, x+1, n)== true){
                x = x + 1;
                cnt++;
            }     
            longest = max (longest, cnt);
        }
        return longest;
    }
};

class OptimalSolution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int longest = 1;
        set<int> st;

        for(int i=0; i<n; i++){
            st.insert(nums[i]); //
        }

        for(auto it: st){
            if(st.find(it - 1) == st.end()){
                int x = it;
                int cnt = 1; //
                while(st.find(x+1) != st.end()){
                    x = x+1;
                    cnt = cnt + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int lastSmallest = INT_MIN;
        int cnt = 0;
        int longest = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i]-1 == lastSmallest){
                cnt ++;
                lastSmallest = nums[i];
            }

            else if(nums[i] != lastSmallest){
                cnt = 1;
                lastSmallest = nums[i];
            } 

            longest = max(longest, cnt);
            
        }

        return longest;
    }
};