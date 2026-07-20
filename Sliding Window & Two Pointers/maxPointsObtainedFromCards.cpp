//Leetcode 1423. Maximum Points You Can Obtain from Cards

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftsum = 0;
        int rightsum = 0;
        int maxsum = 0;
        for(int i=0; i<k; i++){
            leftsum += cardPoints[i];
        }
        maxsum = leftsum;
        int rightind = n-1;
        for(int i =k-1; i>=0; i--){
            leftsum = leftsum - cardPoints[i];
            rightsum += cardPoints[rightind];
            rightind --;

            maxsum = max(maxsum , leftsum + rightsum);
        }
        return maxsum;
    }
};