/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    unordered_map<int, int> freq;
    vector<int> result;

    for (int num : nums) {
        freq[num]++;
        if (freq[num] == 2) {
            result.push_back(num);
        }
    }

    return result;
}
