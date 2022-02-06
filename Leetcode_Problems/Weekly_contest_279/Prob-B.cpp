#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> get_digits(long long num) {
        vector<int> digits;
        while(num) {
            digits.push_back(num%10LL);
            num /= 10LL;
        }
        
        return digits;
    }
    
    long long get_number(vector<int> digits) {
        long long ans = 0;
        for(int digit: digits) {
            ans = ans * 10LL + digit;
        }
        
        return ans;
    }
    long long convert_to_max(long long num) {
        vector<int> digits = get_digits(num);
        sort(digits.begin(), digits.end());
        reverse(digits.begin(), digits.end());
        
        return get_number(digits);
    }
    
    long long convert_to_min(long long num) {
        vector<int> digits = get_digits(num);
        sort(digits.begin(), digits.end());
        for(int i=0;i<digits.size();++i) {
            if(digits[i]) {
                swap(digits[i], digits[0]);
                break;
            }
        }
        
        return get_number(digits);
    }
    
public:
    long long smallestNumber(long long num) {
        if(num < 0) return (-1LL * convert_to_max(abs(num)));
        
        return convert_to_min(num);
    }
};