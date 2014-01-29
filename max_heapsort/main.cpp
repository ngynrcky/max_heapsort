#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>
#include <ctime>

// function prototypes
void heapSort(int [], int);
void buildMaxHeap(int [], int);
void maxHeapify(int [], int, int);
void swap(int &, int &);

int main()
{
	// build the array
	const int SIZE = 10;
	int a[SIZE];

	// intialize and display the contents of the array
	srand(time(NULL)); // seed the rand function
	cout << "The unsorted array is:" << endl;
	for(int i = 0; i < SIZE; i++) {
		a[i] = (rand() % 100) + 1;
		cout << a[i] << ' ';
	}
	cout << '\n' << endl;

	// sort the array using heap sort
	heapSort(a, SIZE);

	// display array after calling heap sort
	cout << "The sorted array is" << endl;
	for(int i = 0; i < SIZE; i++)
		cout << a[i] << ' ';
	cout << endl;

	return 0;
} // end main

// heap sort function
void heapSort(int a[], int length)
{
	int heapSize = length;
	
	// build a max heap
	buildMaxHeap(a, heapSize);

	//sort the heap
	for(int i = heapSize - 1; i >= 1; i--) {
		swap(a[0], a[i]); // place the largest number (root) in its correct position
		heapSize--; // remove the number from the unsorted array
		maxHeapify(a, 0, heapSize); // maintain the max heap property
	}
}

// convert an array to a max heap
void buildMaxHeap(int a[], int length)
{
	// call maxHeapify on subMaxHeaps; ignore the leaves ((length/2) - 1)
	for(int i = (length/2) - 1; i >= 0; i--)
		maxHeapify(a,i,length);
}

// maintain the max heap property on a specific index
void maxHeapify(int a[], int index, int length)
{
	// initialize variables with the index of left and right child
	int l = 2 * index + 1;
	int r = 2 * index + 2;
	int largest;

	// determine the largest node between the left child and the parent
	if(l < length && a[l] > a[index]) // error checking done here; no need to validate if the child is out of range
		largest = l;
	else
		largest = index;

	// determine the largest node between the right child and current largest node
	if(r < length && a[r] > a[largest])
		largest = r;
	
	// if the parent node isn't the largest then swap it with the largest node
	if(largest != index) {
		swap(a[index], a[largest]); // swap the parent node with the larger child node
		maxHeapify(a, largest, length); // recursively calls maxHeapify to check if the child node is a max heap
	}
}

// swap the values
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}