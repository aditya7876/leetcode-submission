#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int deleteCount = 0;
        int numsRows = strs.size();
        int numscols = strs[0].size();

        for(int i = 0; i < numscols; ++i){
            for(int j = 0; j < numsRows - 1; ++j){
                if(strs[j][i] > strs[j + 1][i]){
                    deleteCount++;
                    break;
                }
            }
        }
        return deleteCount;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"cba", "daf", "ghi"};
    int result = solution.minDeletionSize(strs);
    cout << "Minimum number of columns to delete: " << result << endl;
    return 0;
}