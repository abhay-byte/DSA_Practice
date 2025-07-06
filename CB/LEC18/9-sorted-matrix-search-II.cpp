#include<iostream>

#include<algorithm>
using namespace std;

// time: O(mxn) 

bool isPresent(int mat[][3], int m, int n, int t)
{
    int i = 0;
    int j = n - 1;
    while(i < m && j >= 0)
    {
        if(mat[i][j] == t)
        {
            return true;
        }
        else if(mat[i][j] < t)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}

int main()
{
    int mat[][3] = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    int n = 3;
    int m = 3;

    int t = 5;
    
    cout << isPresent(mat,m,n,t);
}