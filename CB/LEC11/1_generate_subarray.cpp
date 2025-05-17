#include <iostream>

using namespace std;

void generateSubArray(int arr[], int n)
{
    for(int i = 0; i<=n-1; i++)
    {
        for(int j = i; j <= n-1; j++)
        {
            cout << i << j << ":";
            for(int k = i; k <=j ; k++)
            {
                cout << arr[k] << " ";
            } 
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    int arr[] = {10,20,30,40,50};
    int n = 5;

    generateSubArray(arr,n);
}