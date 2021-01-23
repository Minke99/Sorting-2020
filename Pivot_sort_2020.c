#include<stdio.h>
int pivot(int *arr, int leftp, int rightp, int len)
{
    int lp = leftp, rp = rightp, pivot = arr[len];
    while(lp <= rp)
    {
        while(lp <= rp && arr[lp] <= pivot) lp++;
        while(lp <= rp && arr[rp] > pivot) rp--;
        if(lp < rp)
        {
            int temp = arr[lp];
            arr[lp] = arr[rp];
            arr[rp] = temp;
        }
    }
    //swap pivot and left
    arr[len] = arr[lp];
    arr[lp] = pivot;
    return lp;
}

void sort(int *arr, int left,int right)
{
    if(left >= right) return;
    int mid = pivot(arr, left, right - 1, right);
    sort(arr, left, mid - 1);
    sort(arr, mid + 1, right);
}

int main()
{
    int arr[] = {7, 6};
    //几个元素len就是几,len - 1意为从0开始的数列。
    int len = sizeof(arr)/sizeof(int);
    printf("len = %d\n", len);
    sort(arr, 0, len-1);
    for(int i = 0; i<len; i++) printf("the %d is %d\n", i, arr[i]);
    return 0;
}
