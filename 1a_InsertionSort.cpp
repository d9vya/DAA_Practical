/*
Q1. i. Implement Insertion Sort (The program should report the number of comparisons)
*/

#include<iostream>
using namespace std;

void display(int *a, int size) {
    cout<<"{ ";
    for(int i=0; i<size; i++ )
	cout<<a[i]<<' ';
    cout<<"}"<<endl;
}

int insertionSort(int *a, int n)
{
  int i, j, k, comparison = 0;
  for(i=1; i<n; i++)
  {
    comparison++;
    k = a[i];
    for(j=i-1; (a[j]>k) && (j>=0); j--)
    {
        comparison += 2;
        a[j+1] = a[j];
    }
    a[j+1] = k;
  }
  return comparison;
}

int main()
{

 int size, i, *arr;

 cout<<"\nEnter the size of array (max. 10): ";
 cin>>size;
 arr = new int[size];
 cout<<"\nEnter the array: \n";
 for(i=0; i<size; i++)
   cin>>arr[i];

 cout<<"\nYour array is: \n";
 display(arr, size);

 cout<<"\nTotal number of comparisons made: "<<insertionSort(arr, size);

 cout<<"\nSorted array is: ";
 display(arr, size);


}
