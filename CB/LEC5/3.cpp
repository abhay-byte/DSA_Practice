#include<iostream>

using namespace std;

int main()
{
  int n;

  cin >> n;

  int a = 0;
  int b = 1;
  int c = 0;
  int i = 0;

  if(n == 0 || n == 1)
  {
    cout << n;
  }
  else{
    while (i != (n-1))
    {
      c = a + b;
      a = b;
      b = c;
      i ++;
    }
  }

  cout << c;
}
