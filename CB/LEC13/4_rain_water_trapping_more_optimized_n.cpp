#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
//time: n steps and each, O(n)
//space: O(1)

int trap(vector<int>& height) {
  int n = height.size();
	int total = 0;


	int i = 0;
	int j = n - 1;

	int l = INT_MIN; // max([0...i])
	int r = INT_MIN; // max([j...n-1])

	while (i <= j) {

		l = max(l, height[i]);
		r = max(r, height[j]);

		if (l < r) {

			int wi = l - height[i];
			total += wi;
			i++;

		} else {

			int wj = r - height[j];
			total += wj;
			j--;

		}

	}

	return total;
}

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << trap(height) << endl;

    return 0 ;

}

