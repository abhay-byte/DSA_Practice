#include<iostream>
#include<climits>
#include<cmath>

using namespace std;

int main()
{

  int n;
  cin >> n;

  int i = 2;
  while (i <= sqrt(n))
  {
    if(n % i == 0)
    {
      cout<< "Not Prime Number.";
      break;
    }

    i++;
  }
  
  if(i>=sqrt(n))
    cout << "Prime";

}

