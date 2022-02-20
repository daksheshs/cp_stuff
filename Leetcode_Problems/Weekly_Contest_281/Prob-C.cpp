#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // typical implementation problem
    string repeatLimitedString(string s, int repeatLimit) {
        int N = s.length();
        map<char,int> mp;
        for(char ch: s) {
            mp[ch]++;
        }
        vector<pair<char, int>> v;
        for(auto it: mp) {
            v.push_back({it.first, it.second});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int i = 0;
        int j = 1;
        int M = v.size();
        int turn = 0;
        string ans;
        while(i < M && j < M) {
            if(turn%2 == 0) {
                int take = min(repeatLimit, v[i].second);
                v[i].second -= take;
                while(take) {
                    take--;
                    ans += v[i].first;
                }
                if(v[i].second == 0) {
                    turn++; //hack
                    i = j;
                    j = i + 1;
                }
            }
            else {
                int take = 1;
                v[j].second -= take;
                while(take) {
                    take--;
                    ans += v[j].first;
                }
                if(v[j].second == 0) j++;
            }
            turn++;
        }

        if(i < M) {
            int take = min(repeatLimit, v[i].second);
            while(take) {
                ans += v[i].first;
                take--;
            }
        }
        
        if(j < M) {
            int take = min(repeatLimit, v[j].second);
            while(take) {
                ans += v[j].first;
                take--;
            }
        }
        
        return ans;
    }
};