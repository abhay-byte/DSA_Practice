#include<iostream>
#include<cstring>

using namespace std;

/*
time: n+n+26 ~ O(n)
space: 26+26 ~ O(1)
*/

bool chechAnagram(char str1[],char str2[])
{
    // building frequency map for str1
    int f1[26] = {0};
    
    for (int i = 0; str1[i] != '\0'; i++)
    {
        f1[str1[i]-'a']++;
    }
    // building frequency map for str1
    int f2[26] = {0};
    
    for (int i = 0; str2[i] != '\0'; i++)
    {
        f2[str2[i]-'a']++;
    }
    // compare two frequency map str1 and str2
    for (int i = 0; i < 26; i++)
    {
        if(f1[i] != f2[i])
        {
            return false;
        }
    }


    return true;

}

int main()
{
    char str1[] = "taste";
    char str2[] = "state";
    cout << chechAnagram(str1,str2);
}