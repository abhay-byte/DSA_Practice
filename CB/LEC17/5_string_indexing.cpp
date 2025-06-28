#include<iostream>
#include<string>

using namespace std;


int main()
{
    string s1 = "Coding Blocks"; //string init
    for(int i = 0; s1[i] != '\0'; i++)
    {
        cout << "s[" << i << "] = " << s1[i] << endl;
    }
}