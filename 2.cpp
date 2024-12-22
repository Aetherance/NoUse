// #include<iostream>
// using namespace std;
// int jie(int n)
// {
//     if(n == 0)return 1;
//     return n * jie(n-1);
// }
// int main()
// {
//     double e = 0.000001;
//     scanf("%lf",&e);
//     double sum = 0;
//     int i = 1;
//     while(1)
//     {
//         sum += 1.0/jie(2*i-1);
//         if(1.0/jie(2*i-1)<e)break;
//         i++;
//     }
//     printf("一共计算了%d项，结果是%0.6lf",i,sum);

//     return 0;
// }