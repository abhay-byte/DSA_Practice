#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//time: 3n steps and each, O(n)
//space: 2n, O(n)

int trap(vector<int>& height) {
    int total = 0;
    int size_of_array = height.size();
    vector<int> l(size_of_array);
    vector<int> r(size_of_array);
    //precomputing value of li
    l[0] = h[0];
    for(int i = 1; i < size_of_array; i++)
    {
        l[i] = max(l[i-1], height[i]);
    }

     //precomputing value of ri
    r[size_of_array-1] = h[size_of_array-1];
    for(int i = n - 2; i >= 0; i--)
    {
        r[i] = max(r[i+1], height[i]);
    }

    for(int i = 0; i < size_of_array; i++)
    {

        int wi = min(l[i] , r[i]) - height[i];
        total += wi;
    }
 
    return total;
}

int main()
{
    vector<int> height = {0,1,2,1,0,1,3,2,1,2,1};

    cout << trap(height) << endl;

    return 0 ;

}

