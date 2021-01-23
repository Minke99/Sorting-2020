#include<stdio.h>
#include"main.h"
void sort(int* arr, int len);

int main()
{
    int arr[] = {7, 6, 2, 1, 4, 9, 3};
    //len is the number of element
    int len = sizeof(arr)/sizeof(int);
    printf("len = %d\n, then call the function of sort", len);
    sort(arr,len);
    return 0;
}
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
