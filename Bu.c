#include<stdio.h>
void Bubble_Sort(int arr[],int len)
{
    for(int i = 0;i<len;i++)
        for(int j = 0;j<len - i - 1;j++)
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}
int main()
{
    int arr[5] = {2,4,1,6,0};
    Bubble_Sort(arr,5);
    for(int i = 0;i<5;i++)
        printf("%d",arr[i]);

    return 0;
}