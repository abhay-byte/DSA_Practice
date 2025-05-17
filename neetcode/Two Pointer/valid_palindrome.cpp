#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {

            string alphaNumericString = "";
            for (char ch : s) {
                if (isalpha(ch) || isdigit(ch)) {
                    alphaNumericString += ch;
                }
            }

            cout<<alphaNumericString<<endl;
            int sizeOfString = alphaNumericString.size();
            int left = 0;
            int right = sizeOfString - 1;

            for (left = 0; left < sizeOfString/2;left++){
                char leftChar = tolower(alphaNumericString[left]);
                char rightChar = tolower(alphaNumericString[right]);
                if( leftChar != rightChar )
                {
                    return false;
                }
                right--;
            }

            return true;
        }
};
    
int main(){
    string s="0p";
    Solution obj1 = Solution();
    cout << obj1.isPalindrome(s);
}