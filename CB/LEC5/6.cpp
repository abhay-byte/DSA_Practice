#include<iostream>
#include<climits>

using namespace std;

int main()
{
  int n;
  cin >> n;
  
  double ans = 0;

  while(ans*ans <= n)
  {
    ans ++;
  }
  ans --;
  while(ans*ans <= n)
  {
    ans += 0.1;
  }
  ans -= 0.1;
  while(ans*ans <= n)
  {
    ans += 0.01;
  }

  ans -= 0.01;
  cout << ans;
    
  return 0;

}
