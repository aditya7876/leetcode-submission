#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> arr(26, false);
        int count = 0;

        for(char c : sentence){
            int index = c - 'a';
            if( arr[index] == false){
                arr[index] = true;
                count++;

                if(count == 26) return true;
            }
        }
        return count == 26;
    }
};

int main() {
    Solution solution;
    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    bool result = solution.checkIfPangram(sentence);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}