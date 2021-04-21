#include<bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void bubbleSort(int arr[], int n) 
{ 
    /*Heaviest element settles down*/

    int i, j; 
    for (i = 0; i < n-1; i++)     
      
    // Last i elements are already in place 
    for (j = 0; j < n-i-1; j++) 
        if (arr[j] > arr[j+1]) 
            swap(&arr[j], &arr[j+1]); 
} 

void insertion(int A[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}
void selection(int A[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (A[j] < A[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&A[min_idx], &A[i]); 
    } 
} 
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quick(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quick(arr, low, pi - 1);
        quick(arr, pi + 1, high);
    }
}
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[100], R[100];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
 
void count(int arr[], int n, int k) 
{ 
    int count[100]; //should be count[k] but not working in vs code.
    for(int i=0;i<k;i++)
        count[i]=0;
    for(int i=0;i<n;i++)
        count[arr[i]]++;
        
    int index=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<count[i];j++){
            arr[index]=i;
            index++;
        }
    }
} 
  
void bucket(int arr[], int n, int k) 
{ 
    int max_val=arr[0]; //finding the maximum element
    for(int i=1;i<n;i++)
        max_val=max(max_val,arr[i]);
        
    max_val++;     
    vector<int> bkt[100]; //should be count[k] but not working in vs code.
  
    for (int i = 0; i < n; i++) {       //scattering into buckets
        int bi = (k * arr[i])/max_val; 
        bkt[bi].push_back(arr[i]); 
    } 
  
    for (int i = 0; i < k; i++)     //sort within individual buckets
        sort(bkt[i].begin(), bkt[i].end()); 
   
    int index = 0; 
    for (int i = 0; i < k; i++) //join sorted buckets (by overwriting in original array)
        for (int j = 0; j < bkt[i].size(); j++) 
            arr[index++] = bkt[i][j]; 
} 
void countingSort(int arr[], int n, int exp) 
{ 
    int output[100];  //should be count[k] but not working in vs code.
    int count[10] = { 0 }; 
    for (int i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 
  
    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (int i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 
  
    for (int i = 0; i < n; i++) 
        arr[i] = output[i]; 
}  
 
void radix(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
  
    for (int exp = 1; mx / exp > 0; exp *= 10) 
        countingSort(arr, n, exp); 
} 
int shell(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
  
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
              
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
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
       cout << "SORTING MENU:\n 1.BUBBLE\n 2.INSERTION\n 3.SELECTION\n 4.QUICK\n 5.MERGE\n 6.COUNT\n 7.BUCKET\n 8.RADIX\n 9.SHELL" << endl;
        int ch;
        cout << "Enter choice:"<<endl;
        cin >> ch;

    switch(ch)
    {
        case 1:{
            bubbleSort(A,n);
            cout << "Sorted Array:" << endl; 
            int i; 
            for (i = 0; i < n; i++) 
            cout << A[i] << " "; 
            cout << endl;            
        }
        break;
        case 2:{
            insertion(A,n);
             cout << "Sorted Array:" << endl; 
            int i; 
            for (i = 0; i < n; i++) 
            cout << A[i] << " "; 
            cout << endl;  
           
        }break;
        case 3:{
            selection(A,n);
             cout << "Sorted Array:" << endl; 
            int i; 
            for (i = 0; i < n; i++) 
            cout << A[i] << " "; 
            cout << endl; 
            
        }break;
        case 4:{
            quick(A,0,n-1);
             cout << "Sorted Array:" << endl; 
            int i; 
            for (i = 0; i < n; i++) 
            cout << A[i] << " "; 
            cout << endl; 

        }break;
        case 5:
        {
            mergeSort(A,0,n-1);
            cout << "Sorted Array:" << endl; 
            int i; 
            for (i = 0; i < n; i++) 
            cout << A[i] << " "; 
            cout << endl;

        }break;
        case 6:{
            int k;
            cout << "Enter max element in the array:"<<endl;
            cin >> k;
            count(A,n,k);
            cout << "Sorted Array:" << endl; 
            int i; 
            for (i = 0; i < n; i++) 
            cout << A[i] << " "; 
            cout << endl;
        }break;
        case 7:{
            int k;
            cout << "Enter number of buckets:"<<endl;
            cin >> k;
            bucket(A,n,k);
            cout << "Sorted Array:" << endl; 
            int i; 
            for (i = 0; i < n; i++) 
            cout << A[i] << " "; 
            cout << endl;
        }break;
         case 8:{
            
            radix(A,n);
            cout << "Sorted Array:" << endl; 
            int i; 
            for (i = 0; i < n; i++) 
            cout << A[i] << " "; 
            cout << endl;
        }break;
        case 9:{
           shell(A,n);
            cout << "Sorted Array:" << endl; 
            int i; 
            for (i = 0; i < n; i++) 
            cout << A[i] << " "; 
            cout << endl; 
        }break;
    }   

        
    cout << "Enter main menu?"<<endl;
    cin >> ans;
    }while(ans=='y');
    
    return 0;
}