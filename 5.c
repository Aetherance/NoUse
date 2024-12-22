#include<stdio.h>
int main()
{
    int n = 0,sum = 0;
    scanf("%d",&n);
    int i = 1;
    int flag = 0;
    while(n--)
    {
        sum += i * (i%2==1?1:-1);
        i++;
    }

    printf("%d",sum);
    return 0;
}