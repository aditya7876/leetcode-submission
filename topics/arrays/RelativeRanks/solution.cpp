#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> order(n);

        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b){
            return score[a] > score[b];
        });

        vector<string> answer(n);

        for (int place = 0; place < n; place++) {
        int who = order[place];

        if (place == 0)
            answer[who] = "Gold Medal";
        else if (place == 1)
            answer[who] = "Silver Medal";
        else if (place == 2)
            answer[who] = "Bronze Medal";
        else
            answer[who] = to_string(place + 1);
    }

    return answer;
    }
};

int main() {
    Solution solution;
    vector<int> scores = {10, 3, 8, 9, 4};
    vector<string> ranks = solution.findRelativeRanks(scores);

    cout << "Relative Ranks: ";
    for (const string& rank : ranks) {
        cout << rank << " ";
    }
    cout << endl; // Output: Gold Medal 5 Bronze Medal Silver Medal 4

    return 0;
}