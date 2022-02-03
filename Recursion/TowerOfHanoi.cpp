// Tower of hanoi: 3 rods and n disks
//1. only one disk can be moved at a time
//2. each move consists of taking the upper disk from one of the stacks and placing it on top of another stack ie. disk can only
// be moved if it is the uppermost disk on a stack.
//3. no disk may be placed on top of a smaller disk

//idea: move n-1 tiles to helper then place the remaining tile to dest and then place
//those n-1 tiles back from helper to dest.

//time O(2^n), space O(1)

#include<bits/stdc++.h>
using namespace std;

void toh(int n, char src, char dest, char helper)
{
    if(n==0)
    {
        return;
    }
    toh(n-1,src,helper,dest); //move n-1 to helper then remaining to dest
    cout << "Move from" << src << "to" << dest << endl;
    toh(n-1,helper,dest,src);   //move n-1 from helper to dest
}
int main()
{
    toh(3,'A','C','B');
}