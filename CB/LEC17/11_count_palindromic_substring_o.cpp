#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

/*
    Time Complexity:
        O(n^2), where n is the length of the input string.
        For each character (and between characters), the function expands outwards to check for palindromes.

    Space Complexity:
        O(1), as the algorithm uses only a constant amount of extra space (excluding input and output).
*/

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

int countPalindromicSubstringOptimised(const string& str)
{
    //for odd length
    int n = str.size();
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        int j = 0;
        while(i - j >= 0 and i + j <= n and str[i-j] == str[i+j])
        {
            j++;
            count++;
        }
    }
    //for even length
    for(double i = 0.5; i < n; i++)
    {
        double j = 0.5;
        while(i - j >= 0 and i + j <= n and str[i-j] == str[i+j])
        {
            j++;
            count++;
        }
    }

    return count;
}

int main()
{
    string s = "abaaba";
    cout << countPalindromicSubstringOptimised(s) << endl;
}