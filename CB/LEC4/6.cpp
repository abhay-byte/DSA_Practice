#include<iostream>

using namespace std;

int main()
{
  char marks;
  cin >> marks;

  if (marks=='A')
    cout << "A: Excellent";
  else if (marks == 'B')
    cout << "B: Very Good";
  else if (marks == 'C')
    cout << "C: Good";
  else if (marks == 'D')
    cout << "D: Average";
  else if (marks == 'E')
    cout << "E: Poor";
  else
    cout << "F: Fail";
}

