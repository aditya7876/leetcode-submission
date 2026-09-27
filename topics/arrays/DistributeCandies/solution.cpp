#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();

        unordered_set<int> kinds;

        for(int c : candyType){
            kinds.insert(c);
        }

        return min((int)kinds.size(), n / 2);
    }
};

int main() {
    Solution solution;
    vector<int> candyType = {1, 1, 2, 2, 3, 3};
    int result = solution.distributeCandies(candyType);
    cout << "Maximum number of different kinds of candies: " << result << endl; // Output: 3
    return 0;
}