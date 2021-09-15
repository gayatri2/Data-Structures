//n=4 then 1 2 3 4

#include<bits/stdc++.h>
using namespace std;

void inc(int n)
{
    if(n==0)
    {
        return;
    }
    inc(n-1);
    cout << n << " ";   //print while returning

}

int main()
{
    int n;
    cin >> n;
   
    inc(n);
}
