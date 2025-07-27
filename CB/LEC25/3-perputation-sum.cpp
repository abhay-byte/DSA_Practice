#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void f(const vector<int> c, int t, vector<int>& perm)
{
    // base case
    if(t == 0){ //valid permutation built
        for(int el : perm)
        {
            cout << el << " ";
        }
        cout << endl;
        return;
    }

    // recursive case
    for(int op : c)
    {
        if(op <= t)
        {
            perm.push_back(op);
            f(c, t - op, perm);
            perm.pop_back(); // backtrack
        }
    }
}

int main()
{
    vector<int> candid = {2 ,3 ,5, 7};
    int target = 7;
    vector<int> perm; //track single permutation

    f(candid, target, perm);
}