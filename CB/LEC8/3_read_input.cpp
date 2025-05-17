#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int Z[5]; //to fill 2
    cout << endl << "ENTER NUMBERS:." << endl;
    for(int i = 0; i < 5; i++)
    {
        cin >> Z[i];
    }
    cout << endl << "INPUT TAKEN." << endl;
    cout << endl << "Printing." << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << Z[i] << " ";
    }
    cout << endl << "Reverse Printing." << endl;
    for(int i = 4; i >= 0; i--)
    {
        cout << Z[i] << " ";
    }

}