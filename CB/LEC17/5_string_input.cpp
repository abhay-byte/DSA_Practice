#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


int main()
{
    string s1; //string init
    // cin >> ws used to ignore leading white spaces
    getline(cin >> ws,s1);

    cout << s1;

    getline(cin >> ws, s1, '$');
    cout << s1;


}