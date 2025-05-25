#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//time: 2n, O(n)
//space: k+1, O(k)

void sort(vector<int>& arr, int k) {
    vector<int> kmap (k+1,0);

    for(int i: arr)
    { //n steps each step is const,
        kmap[i]++;
    }

    for(int i=0; i<=k; i++) { //n steps each step is const
        for (int j = 1; j < kmap[i]; j++) {
            cout << i << " ";
        }
    }
}

int main()
{
    vector<int> arr = {0,0,1,2,1,0,1,3,2,1,2,1};
    sort(arr,3);
    return 0;

}

