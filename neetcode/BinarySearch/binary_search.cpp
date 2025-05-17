#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            return binarySearchRecursive(nums,0,nums.size()-1,target);
        }

        int binarySearchRecursive(vector<int> arr, int left, int right, int target) {
            if (left > right) return -1;
        
            int mid = left + (right - left) / 2;
        
            if (arr[mid] == target) return mid;
            else if (arr[mid] > target) return binarySearchRecursive(arr, left, mid - 1, target);
            else return binarySearchRecursive(arr, mid + 1, right, target);
        }
    };
    