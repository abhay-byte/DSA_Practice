#include<iostream>

using namespace std;

int main()
{
  int marks;
  cin >> marks;

  if (marks>90)
    cout << "A";
  else if (marks > 80 && marks <= 90)
    cout << "B";
  else if (marks > 70 && marks <= 80)
    cout << "C";
  else if (marks > 60 && marks <= 70)
    cout << "D";
  else if (marks > 50 && marks <= 60)
    cout << "E";
  else
    cout << "F";
}
  
