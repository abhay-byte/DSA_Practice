#include <iostream>
#include <set>
using namespace std;

void f(char inp[], char out[10], int i, int j, set<string>& s)
{
    //base case
    if(inp[i]== '\0')
    {
        out[j] = '\0';
        //cout << out << endl;
        string outStr(out);
        s.insert(outStr);
        return;
    }

    out[j] = inp[i];
    f(inp,out,i+1,j+1,s);

    f(inp, out, i+1, j,s);

}

int main(){

    char inp[] = "abc";

    char out[10];
    
    set<string> s;

    f(inp,out,0,0,s);

    for (string i: s)
    {
        cout << i << " " ;
    }
    


}