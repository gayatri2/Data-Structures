//N=5, then factorial = 5*4*3*2*1 = 120

#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if(n==1)
    {
        return 1;
    }
    int prevFact=fact(n-1);
    return n*prevFact;
}

int main()
{
    int n;
    cin >> n;
   
    cout << fact(n) << endl;
}
