#include <iostream>
#include <set>
using namespace std;

void f(char inp[], char out[10], int i, int j)
{
    //base case
    if(inp[i]== '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    //

    out[j] = inp[i];
    f(inp,out,i+1,j+1);

    f(inp, out, i+1, j);

}

int main(){

    char inp[] = "abc";

    char out[10];

    f(inp,out,0,0);


}