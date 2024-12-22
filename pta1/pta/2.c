#include<stdio.h>
#include<math.h>
double fact(int n)
{
    if(n==1)return 1;
    return n*fact(n-1);

}
int main()
{
    int m,n;
    double result;
    scanf("%d%d",&m,&n);

    result = fact(n);
    result /= fact(m)*fact(n-m);

    printf("result = %1.0lf",result);
    return 0;
}