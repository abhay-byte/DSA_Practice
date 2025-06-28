#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

bool checkGoodStrings(string str)
{
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o'|| str[i] == 'u')
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s = "aeiou";
    cout << checkGoodStrings(s);
}