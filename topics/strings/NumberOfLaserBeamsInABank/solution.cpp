#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prev = 0, next = 0;
        int result = 0;

        for(int i = 0; i < n; i++){
            int m = bank[i].size();
            for(int j = 0; j < m; j++){
                if(bank[i][j] == '1')
                    next++;
            }
            if(prev != 0 && next != 0){
                result = result + prev * next;
            }
            if(next != 0){
                prev = next;
                next = 0;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> bank = {"011001", "000000", "010100", "001000"};
    int result = solution.numberOfBeams(bank);
    cout << "Number of laser beams: " << result << endl; // Output: 8
    return 0;
}