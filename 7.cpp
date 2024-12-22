// #include<stdio.h>
// #include<stdlib.h>
// typedef struct result
// {
//    int * arr;
//    int len;
// }result;
// void Bubble_Sort(int arr[],int len)
// {
//    for(int i = 0;i<len;i++)
//    {
//       for(int j = 0;j<len - i - 1;j++)
//       {
//          if(arr[j+1]<arr[j])
//          {
//             int temp = arr[j+1];
//             arr[j+1] = arr[j];
//             arr[j] = temp;
//          }
//       }
//    }
// }
// void your_sort(int arr1[],int len1,int arr2[],int len2,result * result)
// {
//    int len_temp = len1 + len2,count = 0;
//    result->arr = (int *)malloc(len_temp * sizeof(int));
//    for(int i = 0;i<len1;i++)
//    {
//       result->arr[count] = arr1[i];
//       count++;
//    }
//    for(int i = 0;i<len2;i++)
//    {
//       result->arr[count] = arr2[i];
//       count++;
//    }
//    result->len = count;
//    Bubble_Sort(result->arr,result->len);
//    int * arr_temp = (int*)malloc(sizeof(int) * count);
//    if(arr_temp == NULL)exit(-1);
//    int _count = 0;
//    for(int i = 0;i<result->len;i++)
//    {
//       if(result->arr[i]!=result->arr[i+1])
//       {
//          arr_temp[_count] = result->arr[i];
//          _count++;
//       }
//    }
//    result->len = _count;
//    for(int i = 0;i<result->len;i++)
//    {
//       result->arr[i] = arr_temp[i];
//    }
//    free(arr_temp);
// }
// int main() {
//     int arr1[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 10};
//     int arr2[] = {2, 1, 4, 3, 9, 6, 8};
//     int len1 = sizeof(arr1) / sizeof(arr1[0]);
//     int len2 = sizeof(arr2) / sizeof(arr2[0]);

//     result result;
//     your_sort(arr1, len1, arr2, len2, &result);
//     for (int i = 0; i < result.len; i++) {
//         printf("%d ", result.arr[i]);
//     }
//     free(result.arr);
//     return 0;
// }