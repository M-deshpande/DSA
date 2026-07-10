//Leetcode 907. Sum of Subarray Minimums

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>NSE(vector<int>& arr){
        int n = arr.size();
        vector <int> nse(n);
        stack <int> st;
        for(int i=n -1 ; i>=0; i--)  {
            while(!st.empty() && arr[st.top()] >=
             arr[i]) st.pop();

           nse[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return nse;
    }

    vector<int>PSEE(vector<int>& arr){
        int n = arr.size();
        vector <int> psee(n);
        stack <int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            psee[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = NSE(arr);
        
        vector<int> psee = PSEE(arr);

        int n = arr.size();
        
        int sum = 0;

        int mod = 1e9 + 7;

        for(int i=0; i<n; i++){
            int left = i - psee[i];
            int right = nse[i] - i;

            long long freq = left*right*1LL;
            
            int val = (freq*arr[i]*1LL) % mod;
            
            sum = (sum + val) % mod;
        }
        return sum;
    }
};