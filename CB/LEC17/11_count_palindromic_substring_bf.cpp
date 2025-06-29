#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

bool isPalindrome(const string& str)
{
    int i = 0;
    int j = str.size() - 1;

    while (i < j)
    {
        if(str[i] == str[j])
        {
            i++;
            j--;
        }
        else{
            return false;
        }
    }

    return true;

}

int countPalindromicSubstring(const string& str)
{
    int count = 0;
    for(int i = 0; i < str.size(); i++)
    {
        for (int j = i; j < str.size(); j++)
        {
            string substring = str.substr(i,j-i+1);
            if(isPalindrome(substring)) {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    string s = "abaaba";
    cout << countPalindromicSubstring(s);
}