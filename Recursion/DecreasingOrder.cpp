//n=4 then 4 3 2 1 

#include<bits/stdc++.h>
using namespace std;

void dec(int n)
{
    if(n==0)
    {
        return;
    }
    cout << n << " ";
    dec(n-1);
}

int main()
{
    int n;
    cin >> n;
   
    dec(n);
}
