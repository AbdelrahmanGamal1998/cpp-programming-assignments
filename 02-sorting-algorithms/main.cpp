#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

void selectionsort(int arr[],int n)//compare with index
{
    int indexmin,temp;
    for(int i=0;i<n-1;i++)
    {
        indexmin=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[indexmin])
            {
                indexmin=j;
            }
        }
        temp=arr[indexmin];
        arr[indexmin]=arr[i];
        arr[i]=temp;
    }
}

void bubblesort(int arr[],int n)//compare each index with next in each path
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void _merge(int arr[],int l,int m,int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        _merge(arr, l, m, r);
    }
}

int main()
{ int MyArray[100000];

   auto start = high_resolution_clock::now();
   selectionsort(MyArray,100000);
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stop - start);
   cout << "Duration of selection sort = " << duration.count()<<" microseconds"<< endl;

   auto start2 = high_resolution_clock::now();
   bubblesort(MyArray,100000);
   auto stop2 = high_resolution_clock::now();
   auto duration2 = duration_cast<microseconds>(stop2 - start2);
   cout << "Duration of bubble sort = " << duration2.count()<<" microseconds"<< endl;

   auto start3 = high_resolution_clock::now();
   insertionSort(MyArray,100000);
   auto end3 = high_resolution_clock::now();
   auto duration3 = duration_cast<microseconds>(end3 - start3);
   cout << "Duration of insertion sort = " << duration3.count()<<" microseconds"<< endl;

   auto start4= high_resolution_clock::now();
   mergeSort(MyArray,0,99999);
   auto end4 = high_resolution_clock::now();
   auto duration4 = duration_cast<microseconds>(end4 - start4);
   cout << "Duration of merge sort = " << duration4.count()<<" microseconds"<< endl;

   for(int i=0;i<100000;i++)
   {
       MyArray[i]=rand()%100000;
   }
    return 0;
}
