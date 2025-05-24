#include <iostream>
#include <vector>
using namespace std;

//time: n^2.const ~ O(n^2)
//space: O(1)

void pickCardFindSum(vector<int> arr, int n)
{
    int serejaScore = 0;
    int dimaScore = 0;

    int turn = 0;

    int i = 0; int j = n-1;

    while(i<=j)
    {
        if(arr[i] > arr[j])
        {
            if(turn == 0)
            {
                serejaScore+=arr[i];
                turn++;
            }
            else
            {
                dimaScore += arr[i];
                turn--;
            }
            i++;
        }
        else
        {
            if(turn == 0)
            {
                serejaScore+=arr[j];
                turn++;
            }
            else
            {
                dimaScore += arr[j];
                turn--;
            }
            j--;
        }
    }    

    cout << serejaScore << " " << dimaScore;

}

int main()
{
    int n ;
    cin >> n;
    vector<int> arr;
    for(int i; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    pickCardFindSum(arr, n);
}