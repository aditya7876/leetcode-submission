#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for(int len = 1; len <= n/2; ++len){
            if(n % len == 0){
                string sub = s.substr(0 , len);
                string constructed = "";

                for(int i = 0; i < n/len; ++i){
                    constructed += sub;
                }

                if(constructed == s){
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    string s = "abab";
    bool result = solution.repeatedSubstringPattern(s);
    cout << (result ? "True" : "False") << endl; // Output: True
    return 0;
}