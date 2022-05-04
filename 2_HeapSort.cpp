/*
Q2. Implement Heap Sort(The program should report the number of comparisons)
*/

#include <iostream>
using namespace std;

int comparison = 0;

void display(int *a, int size) {
    cout<<"{ ";
    for(int i=0; i<size; i++ )
	cout<<a[i]<<' ';
    cout<<"}"<<endl;
}

void swap(int *a, int x, int y){
  int temp = a[y];
  a[y] = a[x];
  a[x] = temp;
}

void maxHeapify(int *a, int index, int heapSize)
{
  int left = index*2 + 1;
  int right = index*2 + 2;
  int largest = index;

  if(left < heapSize && a[left] > a[largest]){
    largest = left;
	  comparison+=2;
  }
  if(right < heapSize && a[right] > a[largest]){
    largest = right;
	  comparison+=2;
  }

  if(largest != index){
    comparison++;
    swap(a, largest, index);
    maxHeapify(a, largest, heapSize);
  }
}

void buildMaxHeap(int *a, int n)
{
  for (int i = (n/2) - 1; i >= 0; i--) {
    maxHeapify(a, i, n);
    comparison++;
  }
}

void heapSort(int *a, int size)
{
  buildMaxHeap(a, size);
  int heapSize = size, i;
  for(i=size-1; i>=0; i--) {
  	swap(a, 0, i);
  	heapSize--;
  	comparison++;
  	maxHeapify(a,0,heapSize);
  }
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

 heapSort(arr, size);
 cout<<"\nTotal number of comparisons made: "<<comparison;

 cout<<"\nSorted array is: \n";
 display(arr, size);

}
