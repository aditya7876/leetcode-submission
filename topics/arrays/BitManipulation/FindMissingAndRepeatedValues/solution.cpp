#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalNumber = n * n;
        int xorAll = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                xorAll ^= grid[i][j];
            }
        }

        for(int i = 1; i <= totalNumber; ++i){
            xorAll ^= i;
        }

        int mask = xorAll & -xorAll;
        int firstGroup = 0, secondGroup = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if((grid[i][j] & mask) != 0){
                    firstGroup ^= grid[i][j];
                }else {
                    secondGroup ^= grid[i][j];
                }
            }
        }

        for(int i = 1; i <= totalNumber; ++i){
            if((i & mask) != 0){
                firstGroup ^= i;
            }else {
                secondGroup ^= i;
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == firstGroup){
                    return {firstGroup, secondGroup};
                }
            }
        }
        return {secondGroup, firstGroup};
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 8} // Here, 8 is repeated and 9 is missing
    };

    vector<int> result = solution.findMissingAndRepeatedValues(grid);

    cout << "Repeated value: " << result[0] << ", Missing value: " << result[1] << endl;

    return 0;
}