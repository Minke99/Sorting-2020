#include<stdio.h>
int pivot_part(int *arr, int left, int right);
//int times = 1;
void pivot_sort(int *arr,int left, int right)
{
	if(left >= right) return;
	int mid = pivot_part(arr, left, right);
	printf("the %d times ,mid =%d ", times, mid);
	//sort the parts
	//times++;
	pivot_sort(arr, left, mid-1);
	pivot_sort(arr, mid+1, right);
	
}
int pivot_part(int *arr, int left, int right)
{
	int pivot = arr[right];
	int temp;
	int lPtr = left;
	int rPtr = right - 1;
	while(lPtr <= rPtr)
	{
		while(lPtr <= rPtr && arr[lPtr] <= pivot) lPtr++;
		while(lPtr <= rPtr && arr[rPtr] > pivot) rPtr--;
		//printf("the arr[%d] and arr[%d] before swaping is %d,%d ",lPtr, rPtr, arr[lPtr],arr[rPtr]);
		if(lPtr < rPtr) 
		{
			temp = arr[lPtr];
			arr[lPtr]= arr[rPtr];
			arr[rPtr] = temp;
		}
		//printf("and after swaping they are %d,%d\n",arr[lPtr], arr[rPtr]);
	}
	temp = arr[lPtr];
	arr[lPtr]= arr[right];
	arr[right] = temp;
	return lPtr;
}

	
