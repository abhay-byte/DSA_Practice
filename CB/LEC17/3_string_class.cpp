#include<iostream>
#include<string>

using namespace std;


int main()
{
    string s1 = "Coding Blocks"; //string init
    cout << s1 << endl;

    string s2;
    cout << s2.size() << endl; // string declaration
    cout << s2.empty();

    s2 = "hello world"; // string assignment
    cout << s2 << endl;
    cout << s2.size() << endl;
}