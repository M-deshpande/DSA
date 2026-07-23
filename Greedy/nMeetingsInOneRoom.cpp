//GFG

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {

        vector< tuple<int,int,int> > meetings;

        // {finish, index, start}
        for (int i = 0; i < s.size(); i++) {
            meetings.push_back({f[i], i + 1, s[i]});
        }

        // Default tuple sort:
        // finish -> index -> start
        sort(meetings.begin(), meetings.end());

        vector<int> ans;
        int lastEnd = -1;

        for (auto &m : meetings) {
            int end = get<0>(m);
            int pos = get<1>(m);
            int start = get<2>(m);

            if (start > lastEnd) {
                ans.push_back(pos);
                lastEnd = end;
            }
        }

        sort(ans.begin(), ans.end());   // Required by the problem statement

        return ans;
    }
};