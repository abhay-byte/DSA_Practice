#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int* resize(int* A, int c)
{
    cout << "resize from " << c*sizeof(int) << "B to" << 2*c*sizeof(int) << "B" << endl;
    int* B = new int[2*c];
    for(int i =0; i< c; i++)
    {
        B[i] = A[i];
    }
    delete [] A;
    return B;
}

int main()
{

    int* A = new int[5];
    int c = 1;
    int i = 0;

    int x;

    while(true)
    {
        cin >> x;

        if(x < 0)
        {
            break;
        }

        if(i == c)
        {
            A = resize(A,c);
            c = 2*c;
        }

        A[i] = x;
        i++;
    }

    //print dynamic array

    for(int z = 0; z < i; z++)
    {
        cout << A[z] << " " ;
    }

}