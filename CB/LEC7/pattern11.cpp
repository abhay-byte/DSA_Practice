//ABCDE
//ABCD
//ABC
//AB
//A

#include<iostream>
using namespace std;

int main(){

    for (int i=0; i < 9; i++)
    {
        for (int k = 1; k <= 9-i ; k++)
        {
            cout << " "; 
        }

        for(int j=1; j < (2*i-1); j++)
        {
            cout << "*";
        }
        cout << endl;

        for (int k=0; k < 9/2; k++)
        {
            cout << " ";
        }

        for ()
    }
    return 0;
}