#include <stdio.h>
void merge(int *arr,int leftPtr, int midPtr,int rightPtr);
//int time = 0;
void merge_sort(int *arr,int left, int right)
{
	
	int mid = left +(right-left)/2;
	if(left == right) return;
	//divide into 2 parts
	
	//sort the  part of left
	merge_sort(arr, left, mid);
	//sort the other one
	merge_sort(arr, mid+1, right);
	merge(arr, left, mid+1, right);
	//time++;
	//printf("at the %d time , arr[0] = %d,arr[1]=%d\n", time, arr[0],arr[1]);

}
void merge(int *arr,int leftPtr, int midPtr,int rightPtr)
{
	int mid = midPtr-1;
	int temp[rightPtr-leftPtr+1];
	int i = leftPtr;
	int j = midPtr;
	int k = 0;
	//printf("at the %d time ,i = %d, j= %d  \n", time, i, j);
	//left compare with right
	while(i <= mid && j <= rightPtr)
	{
		temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];

	}
	//add the part of arr whose ptr != bound 
	while(i <= mid) temp[k++] = arr[i++];
	while(j <= rightPtr) temp[k++] = arr[j++];
	int tempsize = sizeof(temp)/sizeof(int);
	for(int m = 0; m < tempsize; m++) 
	{
		arr[leftPtr + m] = temp[m];
	}

}
