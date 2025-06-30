#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void findPair(vector<int>& prices, int money) {
    sort(prices.begin(), prices.end());

    int left = 0, right = prices.size() - 1;
    int price1 = 0, price2 = 0;
    int minDiff = INT_MAX;

    while (left < right) {
        int sum = prices[left] + prices[right];

        if (sum == money) {
            int diff = prices[right] - prices[left];
            if (diff < minDiff) {
                price1 = prices[left];
                price2 = prices[right];
                minDiff = diff;
            }
            // Keep searching for better pair
            left++;
            right--;
        }
        else if (sum < money) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << "Deepak should buy roses whose prices are " << price1 << " and " << price2 << "." << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> prices(n);
        for (int i = 0; i < n; ++i) {
            cin >> prices[i];
        }

        int money;
        cin >> money;

        findPair(prices, money);
        cout << endl;  // Blank line after each test case
    }

    return 0;
}
