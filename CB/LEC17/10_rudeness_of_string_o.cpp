#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int rudnessOfString(const string& str)
{
    int rudness = 0;
    int count = 0;
    for(int i = str.size()-1; i >= 0; i--)
    {
        if(str[i] == 'a')
        {
            rudness += count;   
        }
        else if(str[i] == 'b')
        {
            count++;
        }

    }

    return count;
}

int main()
{
    string s = "ababbaab";
    cout << rudnessOfString(s);
}