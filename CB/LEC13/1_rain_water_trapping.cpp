#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int trap(vector<int>& height) {
    int total = 0;
    int size_of_array = height.size();

    for(int i = 0; i < size_of_array; i++)
    {
        int li = height[i];
        for(int j = 1; j <= i; j++)
        {
            li = max(height[j],li);
        }

        int ri = height[size_of_array-1];
        for(int j = i+1; j < n; l++)
        {
            if (li < height[j])
            {
                ri = max(height[j],ri);
            }
        }
        int wi = min(li , ri) - height[i];
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

