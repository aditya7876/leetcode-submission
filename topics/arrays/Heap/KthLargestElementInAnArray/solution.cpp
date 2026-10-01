#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<int>> min_heap;

       for(int num : nums){
        min_heap.push(num);
        if(min_heap.size() > k){
            min_heap.pop();
        }
       }
        return min_heap.top();
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int kthLargest = solution.findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << kthLargest << endl;

    return 0;
}