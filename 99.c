#include<stdio.h>
#include<stdlib.h>
typedef struct{ 
    int * arr;
    int len;
} result;
void your_sort(int *arr1,int len1,int * arr2, int len2,result *result){
int sum_len = len1+ len2;
int * mid = (int*)malloc(sizeof(int)*sum_len);
int i = 0,j = 0, k = 0;
for(i = 0; i < sum_len;i++){
   if(i<len1){
     for(j = 0;j < len1;j++)
       mid[j] = arr1[j];
   }
   if(i>=len1){
     for(k = len1;k <len2; k++)
       mid[k] = arr2[k -len1];
   }
}
int cha = 0;
for(i = 0;i<sum_len;i++){
   for(j = 0;j<sum_len-i-1;j++){
     if(mid[j] > mid[j+1]){
      cha = mid[j];
      mid[j] = mid[j+1];
      mid[j+1] = cha;
      }
   }
}
int new_len = 0;
result -> arr = (int*)malloc(sizeof(int)*sum_len);
for(i = 0;i < sum_len; i++){
   if(mid[i] != mid[i+1]){
     result->arr[new_len++] = mid[i];
   }
result -> len = new_len ;
}
free(mid);
}


int main() {
    int arr1[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 10};
    int arr2[] = {2, 1, 4, 3, 9, 6, 8};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    result result;
    your_sort(arr1, len1, arr2, len2, &result);
    for (int i = 0; i < result.len; i++) {
        printf("%d ", result.arr[i]);
    }
    free(result.arr);
    return 0;
}
