#include<stdio.h>
void merge(int *arr, int leftp, int rightp, int len)
{

    int mid = rightp - 1;
    //数列【1，2，3】len = 3， leftp = 0， 数列长度是3。
    int temp[len-leftp+1];
    int i = leftp, j = rightp, k = 0;
    printf("len = %d, mid = %d\n", len,mid);
    while(i<=mid && j<=len)
    {
        (arr[i]<=arr[j])? (temp[k++] = arr[i++]): (temp[k++] = arr[j++]);
        printf("k = %d, arri = %d, arrj = %d, temp = %d\n",k,arr[i], arr[j], temp[k-1]);
    }
    while(i<=mid) temp[k++] = arr[i++];
    while(j<=len) temp[k++] = arr[j++];
    //将temp长度的数列顺序，对应地放到arr中，所以arr从leftp开始。
    for(i = 0; i<(len-leftp+1); i++) arr[leftp+i] = temp[i];
    for(i = 0; i<(len-leftp+1); i++) printf("%d,",temp[i]);
    printf("\n\n");
}

void sort(int *arr, int left,int right)
{
    //mid就是中间那个数，向下取整。
    int mid = left+(right-left)/2;
    if (left == right) return;
    printf("right in sort = %d\nleft in sort = %d\nmid in sort = %d\n", right, left, mid);
    //左半边与右半边。
    sort(arr, left, mid);
    sort(arr, mid+1, right);
    //若数列有五个元素，mid会是2，后一半从3开始，所以mid+1.
    merge(arr, left, mid+1, right);
}

int main()
{
    int arr[] = {1,23,3,4,1,2};
    //几个元素len就是几,len - 1意为从0开始的数列。
    int len = sizeof(arr)/sizeof(int);
    printf("len = %d\n", len-1);
    sort(arr, 0, len-1);
    for(int i = 0; i<len; i++) printf("%d\n", arr[i]);
    return 0;
}