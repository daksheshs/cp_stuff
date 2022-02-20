#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digit_sum(int N) {
        int sum = 0;
        while(N) {
            sum += N % 10;
            N /= 10;
        }
        
        return sum;
    }
    int countEven(int num) {
        int ans = 0;
        for(int i=1;i<=num;++i) {
            if(digit_sum(i)%2 == 0) ans++;
        }
        
        return ans;
    }
};