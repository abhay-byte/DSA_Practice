#include<iostream>
using namespace std;

//Time: O(n^2)

void TransposeMatrix(int mat[][10],int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            swap(mat[i][i], mat[j][i]);
        }
    }
}

int main()
{
    int matrix[10][10]
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int n = 3;

    cout << "Before Transpose: "<< endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    TransposeMatrix(matrix,n);

    cout << "After Transpose: "<< endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}