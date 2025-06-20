/*
Time Complexity: O(N)
Space Complexity: O(N)

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int size = intervals.size();

        sort(intervals.begin(), intervals.end());

        for(int i = 1; i < size; i++)
        {
            if(intervals[i-1][1] >= intervals[i][0])
            {
                if(!result.empty())
                {
                    if(result[result.size()-1][1] == intervals[i][0])
                    {
                        int temp = result[result.size()-1][0];
                        result.pop_back();
                        result.push_back({temp,intervals[i][1]});
                        continue;
                    }
                }
                
                result.push_back({intervals[i-1][0], intervals[i][1]});
            }
            else
            {
                result.push_back({intervals[i-1][0],intervals[i-1][1]});
            }
        }
        if(result.empty())
            return intervals;

        return result;

    }
};*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        // Sort intervals by starting time
        sort(intervals.begin(), intervals.end());

        // Initialize the merged interval with the first interval
        vector<int> currentInterval = intervals[0];

        for (const auto& interval : intervals) {
            // If intervals overlap, merge them
            if (currentInterval[1] >= interval[0]) {
                currentInterval[1] = max(currentInterval[1], interval[1]);
            } else {
                // Otherwise, add the current interval to result and start a new one
                result.push_back(currentInterval);
                currentInterval = interval;
            }
        }

        // Add the last interval
        result.push_back(currentInterval);

        return result;
    }
};
int main()
{
    vector<vector<int>> t1 = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> t2 = {{1,4},{5,6}};
    int target = 0;

    Solution obj = Solution();

    vector<vector<int>> solution = obj.merge(t2);

    for (vector<int> i : solution)
    {
        for (int j : i)
        {
            cout << j << " ";
        }

        cout << endl;
    }
    cout << solution.size();
}