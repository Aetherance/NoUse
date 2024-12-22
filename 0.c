// #include<stdio.h>
// #include<stdlib.h>
// #include<assert.h>
// typedef int (*Predicate)(int);//给指向 参数为int 返回值为int 的函数指针定义一个别名predicate方便使用
// int *filter(int *array, int length, Predicate predicate,int *resultLength)
// {
//     int count = 0;//计数
//     int * filteredNumbers = (int*)malloc(sizeof(int)*length);//使用malloc动态开辟内存
//     assert(filteredNumbers);//判断是否开辟成功 防止传入空指针
//     for(int i = 0;i<length;i++)
//     {
//         if((*predicate)(array[i]))//通过函数指针调用筛选的函数 如果判断条件为真 将要筛选的数放入array
//         {
//             filteredNumbers[count] = array[i];
//             count++;
//         }
//     }
//     *resultLength = count;      //长度变为count
//     return filteredNumbers;//返回筛选后的数组地址
// }
// int isPositive(int num) { return num > 0; }
// int main(void) {
//     int array[] = {-3, -2, -1, 0, 1, 2, 3, 4, 5, 6};
//     int length = sizeof(array) / sizeof(array[0]);
//     int resultLength;
//     int *filteredNumbers = filter(array, length, isPositive,
//                                   &resultLength);
//     for (int i = 0; i < resultLength; i++) {
//         printf("%d ", filteredNumbers[i]);
//     }
//     printf("\n");
//     free(filteredNumbers);
//     return 0;
// }