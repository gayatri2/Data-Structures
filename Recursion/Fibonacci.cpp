//n=4 ie 4th term of 0,1,1,2,3,5,.... series

#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    int prev1=fib(n-1);
    int prev2=fib(n-2);
    return prev1+prev2;
}

int main()
{
    int n;
    cin >> n;
   
    cout << fib(n) << endl;
}
