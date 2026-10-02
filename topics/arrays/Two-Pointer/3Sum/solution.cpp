#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> answer;

        sort(nums.begin() , nums.end());

        for(int i = 0; i <= nums.size() - 3 ; i++){

            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            int left = i + 1;
            int right = nums.size() -1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0){
                    answer.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                      while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                      while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
                else if(sum < 0){
                    left ++;
                
                }
                else{
                    right --;
                }
            }
        }
        return answer;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = solution.threeSum(nums);

    cout << "Unique triplets that sum up to zero:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i < triplet.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}