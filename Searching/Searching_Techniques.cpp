#include<iostream>
using namespace std;

int linear(int A[], int n, int key)
{
    /*
        O(n) time complexity. 
    */
    
    for(int i=0;i<n;i++)
    {
        if(A[i]==key)
        {
            return i;
        }
    }
    return -1;
}
int binary (int A[], int n, int key)
{
    /*
        O(log n) time complexity. 
        Requires sorted array.
        Divide and conquer approach.
    */
    int i=0; int j=n-1;
    int mid=(i+j)/2;

    while(A[mid]!=key && i<=j)
    {
        if(key > A[mid])
        {
            i=mid+1;
        }
        else if(key < A[mid])
        {
            j=mid-1;
        }
        mid=(i+j)/2;

    }
    if(i<=j)
    {
        return mid;
    }
    else{
        return -1;
    }
}

int sentinel (int A[], int n, int key)
{
    /*
        O(n) time complexity. 
    */

    // Last element of the array
    int last = A[n - 1];
 
    // Element to be searched is
    // placed at the last index
    A[n - 1] = key;
    int i = 0;
 
    while (A[i] != key)
        i++;
 
    // Put the last element back
    A[n - 1] = last;
 
    if ((i < n - 1) || (A[n - 1] == key))   //check if key is present before the last element,OR, now since the last element is put back, we check if that last element is the key or not.
        return i;
    else
        return -1;
}
int min(int x, int y) { return (x <= y) ? x : y; }

int fibonacci (int A[], int n, int key)
{
    /*
        O(log n) time complexity. 
        Requires sorted array.
        Divide and conquer approach.
        Divides given array into unequal parts

        Refer to this video: https://youtu.be/kLW_LFv_L-M
    */
   /* Initialize fibonacci numbers */
    int fibMMm2 = 0; // (m-2)'th Fibonacci No.
    int fibMMm1 = 1; // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci
 
    /* fibM is going to store the smallest Fibonacci
       Number greater than or equal to n */
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
    
    // Marks the eliminated range from front
    int offset = -1;
 
    /* while there are elements to be inspected. Note that
       we compare arr[fibMm2] with key. When fibM becomes 1,
       fibMm2 becomes 0 */
    while (fibM > 1) {
        // Check if fibMm2 is a valid location
        int i = min(offset + fibMMm2, n - 1);
 
        /* If key is greater than the value at index fibMm2,
           cut the subarray array from offset to i */
        if (A[i] < key) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
 
        /* If key is greater than the value at index fibMm2,
           cut the subarray after i+1  */
        else if (A[i] > key) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
 
        /* element found. return index */
        else
            return i;
    }
 
    /* comparing the last element with x */
    if (fibMMm1 && A[offset + 1] == key)    // since last element does not get checked in the previous while loop
        return offset + 1;
 
    /*element not found. return -1 */
    return -1;
}



int main()
{
    int n; int *A;
    cout << "Enter the number of elements:"<<endl;
    cin >> n;
    A=new int[n]; //dynamically allocating the array.
    cout << endl << "Enter array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }
     for(int i=0;i<n;i++)
    {
        cout <<  A[i] << " ";
    }
    cout << endl;

    char ans;
    do{
       cout << "SEARCHING MENU:\n 1.LINEAR\n 2.BINARY\n 3.SENTINEL\n 4.FIBONACCI" << endl;
        int ch;
        cout << "Enter choice:"<<endl;
        cin >> ch;
        int key;
        cout << "Enter key to be searched:"<<endl;
        cin >> key; 

    switch(ch)
    {
        case 1:{
            int loc=linear(A,n,key);
            if(loc!=-1)
            {cout << endl << "Element at index:"<< loc+1 << endl;}
            else
            {cout << "Element not found:"<<endl; } 
        }
        break;
        case 2:{
            int loc1=binary(A,n,key);
            if(loc1!=-1)
            {cout << endl << "Element at index:"<< loc1+1 << endl;}
            else
            {cout << "Element not found:"<<endl; }
        }break;
        case 3:{
            int loc2=sentinel(A,n,key);
            if(loc2!=-1)
            {cout << endl << "Element at index:"<< loc2+1 << endl;}
            else
            {cout << "Element not found:"<<endl; }
        }break;
        case 4:{
            int loc3=fibonacci(A,n,key);
            if(loc3!=-1)
            {cout << endl << "Element at index:"<< loc3+1 << endl;}
            else
            {cout << "Element not found:"<<endl; }
        }break;
        
    }   

        
    cout << "Enter main menu?"<<endl;
    cin >> ans;
    }while(ans=='y');
    
}