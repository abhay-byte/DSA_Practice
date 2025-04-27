#include<iostream>
#include<cstring>
using namespace std;

int main(){

    //array initialization
    int array[5] = {1,2,3,4,5}; //size setting is optional here
    for(int i = 0; i < 5; i++)
    {
        cout << endl << array[i] << " ";
    }
    //int array[5] = {1,2,3,4,5,6}; ERROR: NOT ALLOWED EXCCEDING THE ARRAY SIZE  

    int A[5] = {1,2,3}; //ZERO WILL BE FILLED
    cout << endl << "1." << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << A[i] << " ";
    }

    int B[5] = {0}; //ZERO WILL BE FILLED
    cout << endl << "2." << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << B[i] << " ";
    }

    int C[5] = {}; //ZERO WILL BE FILLED
    cout << endl << "3." << endl;
    for(int i = 0; i < 5; i++)
    {
        cout  << C[i] << " ";
    }

    //memset() can be use

    int F[5];
    memset(F,0,sizeof(F));
    cout << endl << "4." << endl;
    for(int i = 0; i < 5; i++)
    {
        cout  << F[i] << " ";
    }

    int G[5];
    memset(G,-1,sizeof(F));
    cout << endl << "5." << endl;
    for(int i = 0; i < 5; i++)
    {
        cout  << G[i] << " ";
    }

    int H[5];
    memset(H,2,sizeof(F)); //memset can only be used to init arr with 0 or -1
    cout << endl << "6." << endl;
    for(int i = 0; i < 5; i++)
    {
        cout  << H[i] << " ";
    }

    int Z[5]; //to fill 2
    cout << endl << "Filling with 2." << endl;
    for(int i = 0; i < 5; i++)
    {
        Z[i] = 2;
        cout  << Z[i] << " ";
    }

    return 0;
}
