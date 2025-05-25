#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int maxofArea = 0;
    int l = 0;
    int r = n-1;

    while(l<r)
    {
        int wlr = r-l;
        int hlr = min(height[r],height[l]);
        int alr = wlr*hlr;

        maxofArea = max(maxofArea,alr);
        if(height[l]>height[r])
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    return maxofArea;
}

int main()
{
    vector<int> a = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(a);

}

