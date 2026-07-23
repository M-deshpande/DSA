//GFG

#include <bits/stdc++.h>
using namespace std;

class BruteSolution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int ans = 1;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                    (arr[j] >= arr[i] && arr[j] <= dep[i])) {
                    count++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
    
};

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int platforms = 0;
        int result = 1;
        int i = 0, j = 0;

        
        while (i < n && j < n) {
            
            if (arr[i] <= dep[j]) {
                platforms++;
                i++;
            } else {
                platforms--;
                j++;
            }

            result = max(result, platforms);
        }

        return result;
        
    }

};