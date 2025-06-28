#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void generateSubstrings(string str)
{
    for(int i = 0; i < str.size(); i++)
    {
        for(int j = i; j < str.size(); j++)
        {
            cout << str.substr(i,j-i+1);
            cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    string s = "abcde";
    generateSubstrings(s);
}