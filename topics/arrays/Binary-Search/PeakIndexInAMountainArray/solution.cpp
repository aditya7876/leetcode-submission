#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0 , high = arr.size() - 1;
        while(low < high){
            int mid = (low + high) / 2;
            if(arr[mid] < arr[mid + 1]){
                low = mid + 1 ;
            }else{

            high = mid;
            }
        }
        return low;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {0, 2, 1, 0};
    int peakIndex = solution.peakIndexInMountainArray(arr);
    cout << "Peak index in the mountain array: " << peakIndex << endl; // Output: 1
    return 0;
}