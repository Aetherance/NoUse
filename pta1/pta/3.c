#include<stdio.h>
#include<math.h>
int isPrime(int num)
{
    if(num==1||0)return 0;
    for(int i = 2;i<=sqrt(num);i++)
        if(num % i == 0)
            return 0;
    return 1;
}
int main()
{
    int n,p;
    scanf("%d",&n);
    if (n<0)n=0;
    p = n+1;
    while(1)
    {
        if(isPrime(p)&&isPrime(p+2))
            break;
        p++;
    }

    printf("%d %d",p,p+2);

    return 0;
}