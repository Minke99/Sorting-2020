#include<stdio.h>
#include"main.h"
void sort(int* arr, int len)
int main()
{
    int arr[] = {7, 6, 2, 1, 4, 9, 3};
    //len is the number of element
    int len = sizeof(arr)/sizeof(int);
    printf("len = %d\n, then call the function of sort", len);
    sort(arr,len);
    return 0;
    printf("sgg has modified this file");
}
void sort(int* arr, int len)
{
	merge_sort();
	pivot_sort();
}
