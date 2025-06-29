#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
bool checkGoodStrings(const string& str)
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
bool longestGoodStrings(const string& str)
{
    int maxSoFar = 0;
    for(int i = 0; i < str.size(); i++)
    {
        for (int j = i; j < str.size(); j++)
        {
            string substring = str.substr(i,j-i+1);
            if(checkGoodStrings(substring)) {
                maxSoFar = max(maxSoFar,i,j-i+1);
            }
        }
    }

    return maxSoFar;
}

int main()
{
    string s = "aeiouadf";
    cout << checkGoodStrings(s);
}