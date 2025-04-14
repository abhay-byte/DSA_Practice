#include<iostream>

using namespace std;

int main()
{
  int a; int b; int c;

  cout << "Enter Principal, Rate and Time: " << endl;

  cin >> a >> b >> c ;

  float result = (a * b * c)/100.0;

  cout << "Simple Interest is: " << result ; 
}
  
