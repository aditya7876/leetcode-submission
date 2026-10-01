#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
         int lo = 1;
        int hi = *max_element(candies.begin(), candies.end());
        int best = 0;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            long long count = 0;

            for (int pile : candies) {
                count += pile / mid;
            }

            if (count >= k) {
                // mid is possible
                best = mid;
                lo = mid + 1;
            }
            else {
                // mid is too large
                hi = mid - 1;
            }
        }

        return best;
    }
};


int main() {
    Solution solution;
    vector<int> candies = {5, 8, 6};
    long long k = 3;
    int maxCandies = solution.maximumCandies(candies, k);
    cout << "Maximum candies that can be allocated to " << k << " children: " << maxCandies << endl;

    return 0;
}