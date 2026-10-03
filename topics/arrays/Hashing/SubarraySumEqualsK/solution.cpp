#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // Prefix sum = 0 initially
        mp[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;

            // Check if required previous prefix exists
            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }

            // Store current prefix sum
            mp[prefixSum]++;
        }

        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int result = solution.subarraySum(nums, k);
    
    cout << "Number of subarrays that sum to " << k << ": " << result << endl;
    
    return 0;
}