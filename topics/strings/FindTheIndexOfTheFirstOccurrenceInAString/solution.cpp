#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if(m > n) return -1;

        for(int i = 0; i <= n; i++){
            for(int j = 0; j < m; j++){
                if(haystack[i + j] != needle[j])
                    break;
                if(j == m - 1) return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    string haystack = "hello";
    string needle = "ll";
    int result = solution.strStr(haystack, needle);
    cout << "Index of first occurrence: " << result << endl;
    return 0;
}