#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char ch = 'A';
    cout << "isalpha: " << isalpha(ch) << endl;
    cout << "isdigit: " << isdigit(ch) << endl;
    cout << "isalnum: " << isalnum(ch) << endl;
    cout << "islower: " << islower(ch) << endl;
    cout << "isupper: " << isupper(ch) << endl;
    cout << "toupper: " << (char)toupper('b') << endl;
    cout << "tolower: " << (char)tolower('Z') << endl;

    char space = ' ';
    cout << "isspace: " << isspace(space) << endl;

    char sym = '!';
    cout << "ispunct: " << ispunct(sym) << endl;

    return 0;
}
