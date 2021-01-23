#include<stdio.h>
#include"main.h"
void sort(int* arr, int len);
// Here is the start of the all programs.
// Function main init the arr and send it to the function sort with its length.
int main()
{
    int arr[] = {7, 6, 2, 1, 4, 9, 3};
    //len is the number of element
    int len = sizeof(arr)/sizeof(int);
    printf("len = %d\n, then call the function of sort", len);
    sort(arr,len);
    return 0;
    printf("sgg has modified this file-2021.1.13");
}
// It provide 2 potral of the sort functions, merge and pivot.
// I did not init the input for them, try yourself in the other scripts and declear them here.
// You cannot use them at the same run.
// Comment one of them and run(shown below).
void sort(int* arr, int len)
{
	printf("Start merge sort now\n");
	merge_sort();
	printf("The result of the merge sort is: ");
	for (int i = 0; i<len; i++)
	{
		printf("%d ", arr[i]);
	}
	
	// printf("Start pivot sort now\n");
	// pivot_sort();
	// printf("The result of the pivot sort is: ");
	// for (int i = 0; i<len; i++)
	// {
		// printf("%d ", arr[i]);
	// }
	
}
