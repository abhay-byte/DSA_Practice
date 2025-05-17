//ABCDE
//ABCD
//ABC
//AB
//A

#include<iostream>
using namespace std;

int main(){

    for (int i=0; i < 5; i++)
    {
        char ch = 'A';
        for(int j=1; j< 5-i+1; j++)
        {
            cout << ch;
            ch++;
        }
        cout << endl;
    }
    return 0;
}