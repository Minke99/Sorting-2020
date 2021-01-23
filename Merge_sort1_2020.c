#include<stdio.h>
void merge(int *arr, int lp, int rp, int bound)
{
    printf("下面开始\n");
    for(int a = lp; a<=bound; a++)
        printf("%d,",arr[a]);
    printf("\n");
    int mid = rp-1;
    int temp[bound - lp + 1];
    int i = lp, j = rp, k = 0;
    while(i<=mid && j<=bound)
        (arr[i] <= arr[j])? (temp[k++] = arr[i++]): (temp[k++] = arr[j++]);
    while(i<=mid)
        temp[k++] = arr[i++];
    while(j<=bound)
        temp[k++] = arr[j++];
    for(int a = 0; a < bound - lp + 1; a++)
        arr[lp+a] = temp[a];

    for(int a = 0; a <= bound - lp + 1; a++)
        printf("%d,", temp[a]);
    printf("\n\n");
}

void sort(int *arr, int left, int right)
{
    int mid = left+(right - left)/2;
    if(left == right) return;
    //recrusion
    sort(arr, left, mid);
    sort(arr, mid+1, right);
    merge(arr, left, mid+1, right);
}

int main()
{
    int arr[] = {3,4,12,2,3,24,1,11,1,23,12,31};
    sort(arr, 0, sizeof(arr)/sizeof(int)-1);
    for(int a = 0; a < sizeof(arr)/sizeof(int); a++)
        printf("%d,", arr[a]);
    printf("\n");
    return 0;
}
