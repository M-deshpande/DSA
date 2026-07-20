//Leetcode 3. Longest Substring Without Repeating Characters  

#include <bits/stdc++.h>
using namespace std;

class bruteSolution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            vector<int> hash(256, 0);
            for(int j=i; j<n; j++){
                if(hash[s[j]] != 0){
                    break;
                }
                int len = j - i + 1;
                maxlen = max(maxlen, len);
                hash[s[j]] = 1;
            }
        }
        return maxlen;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        vector<int>hash(256, -1);
        while(r < n){
            if(hash[s[r]] != -1){
                l = max(hash[s[r]] + 1, l);
            }
            maxLen = max(maxLen , r - l + 1);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};