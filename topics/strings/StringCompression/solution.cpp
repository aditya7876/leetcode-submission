#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int j = 0;
        int count = 1;

        for(int i = 0; i < chars.size(); ++i){
            if(i == chars.size() - 1 || chars[i] != chars[i + 1]){
                chars[j++] = chars[i];

                if(count > 1){
                    for(char c : to_string(count)){
                        chars[j++] = c;
                    }
                }
                count = 1;
            }else{
                count++;
            }
        }
        return j;
    }
};

int main() {
    Solution solution;
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength = solution.compress(chars);
    
    cout << "Compressed length: " << newLength << endl;
    cout << "Compressed characters: ";
    for(int i = 0; i < newLength; ++i){
        cout << chars[i];
    }
    cout << endl;

    return 0;
}