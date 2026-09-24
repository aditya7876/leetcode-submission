#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1 ;
        int i = m - 1 ;
        int j = n - 1 ;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i] ;
                i-- ;
                k-- ; 
            }
            else {
                nums1[k] = nums2[j] ;
                j-- ;
                k-- ;
            }
        } 
        while(j >= 0){
            nums1[k] = nums2[j];
            j-- ;
            k--;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    solution.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl; // Output: Merged array: 1 2 2 3 5 6
    return 0;
}