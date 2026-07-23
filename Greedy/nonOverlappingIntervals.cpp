//Leetcode 435. Non-overlapping Intervals

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int> > & intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int cnt = 0;
        int lastEnd = intervals[0][1];
        int keep = 1;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] >= lastEnd){
                keep ++;
                lastEnd = intervals[i][1];
            }
        }
        return intervals.size() - keep;
    }
};