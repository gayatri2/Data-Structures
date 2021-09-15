//N=2, P=4 then answer = 2*2*2*2 = 2*(2^3) = 16

#include<bits/stdc++.h>
using namespace std;

int power(int n, int p)
{
    if(p==0)
    {
        return 1;   //since p^0=1
    }
    
    int prevPower=power(n,p-1);
    return n*prevPower;
}

int main()
{
    int n;
    cin >> n;
    int p;
    cin>>p;
    cout << power(n,p) << endl;
}
