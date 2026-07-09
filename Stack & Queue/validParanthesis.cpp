#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if( s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }

            else {
                if(st.empty()) return false;

                char ch = st.top();
                st.pop();
                if(ch == '(' && s[i] == ')') continue;
                if(ch == '{' && s[i] == '}') continue;
                if(ch == '[' && s[i] == ']') continue;

                return false;
            }
        }
        return st.empty();
    }
};