#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int> a, vector<int> b)
{
    int n = a.size();
    int m = b.size();

    vector<int> c(n+m);

    int i = 0; int j = 0; int k = 0;

    while(i < n && j < m)
    {
        if(a[i] < b[j])
        {
            c[k] =  a[i];
            i++;
            k++;
        }
        else if(a[i] > b[j])
        {
            c[k] =  b[j];
            j++;
            k++;
        }
    }

    while(i < n)
    {
        c[k] = a[i];
        i++; k++;
    }

    while(j < m)
    {
        c[k] = a[j];
        j++; k++;
    }
    return c;
}

int main()
{
    vector<int> a = {10,20,30,40,50};
    vector<int> b = {20,40,60};

    vector<int> c = merge(a,b);

    for(int i: c)
    {
        cout << i << endl;
    }

}