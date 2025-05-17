#include<iostream>
#include<climits>

using namespace std;

int main()
{
  int lsr = INT_MIN;

  int n;
  cin >> n;

  while (n!=0)
  {
    int temp;
    cin >> temp;

    if(temp > lsr)
    {
      lsr = temp;
    }

    n--;
  }

  cout << lsr;
}
