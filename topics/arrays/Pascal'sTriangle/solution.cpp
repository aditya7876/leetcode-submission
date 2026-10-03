#include<iostream>
#include <vector>
    
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int r = 0; r < numRows; r++) {

            vector<int> row(1, 1);

            for (int c = 1; c < r; c++) {
                row.push_back(
                    triangle[r - 1][c - 1] + 
                    triangle[r - 1][c]
                );
            }

            if (r > 0) {
                row.push_back(1);
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};


int main() {
    Solution solution;
    int numRows = 5;
    vector<vector<int>> result = solution.generate(numRows);
    
    cout << "Pascal's Triangle with " << numRows << " rows:\n";
    for (const auto& row : result) {
        cout << "[";
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i];
            if (i < row.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    
    return 0;
}