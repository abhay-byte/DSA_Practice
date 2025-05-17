#include<iostream>

using namespace std;

int main()
{
  int n = 123;
  int num = 0;



  while( n > 0)
  {
    int d = n  % 10;
    num = num*10 + d;  
    n = n /10;
  }

  cout << num;

}
