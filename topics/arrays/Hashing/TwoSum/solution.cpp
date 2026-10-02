#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> numToIndex;

        for(int currentIndex = 0; currentIndex < nums.size(); ++currentIndex){
            int currentNum = nums[currentIndex];
            int complement = target - currentNum;

            if(numToIndex.count(complement) > 0){
                int previousIndex = numToIndex[complement];
                return {previousIndex, currentIndex};
            }
            numToIndex[currentNum] = currentIndex;
        }
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);

    cout << "Indices of the two numbers that add up to " << target << ": ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}