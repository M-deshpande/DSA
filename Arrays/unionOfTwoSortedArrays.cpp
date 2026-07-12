//GFG

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        int m = b.size();
        vector<int>unionArr;
        
        int i = 0, j = 0;
        while(i < n && j < m){
            if(a[i] <= b[j]){
                if(unionArr.empty() || unionArr.back() != a[i]){
                    unionArr.push_back(a[i]);
                }
                i++;
            }
            else {
                if(unionArr.empty() || unionArr.back() != b[j]){
                    unionArr.push_back(b[j]);
                }
                j++;
            }
        }
        
        while(i < n){
            if(unionArr.empty() || unionArr.back() != a[i]){
                    unionArr.push_back(a[i]);
            }
            i++;    
        }
        
        while(j < m){
           if(unionArr.empty() || unionArr.back() != b[j]){
                    unionArr.push_back(b[j]);
            }
            j++;
        }
        return unionArr;
    }
};