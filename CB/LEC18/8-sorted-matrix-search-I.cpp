#include<iostream>

#include<algorithm>
using namespace std;

// time: O(mxn) 

bool isPresent(int mat[][3], int m, int n, int t)
{
 
    for(int i = 0; i < m; i++)
    {
        if(binary_search(mat[i], mat[i]+n, t)) //        if(binary_search(mat[i], mat[i+1], t)) will not use
        {
            return true;
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