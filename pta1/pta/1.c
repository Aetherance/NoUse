#include<stdio.h>
#include<math.h>
int isPrime(int num)
{
    if(num==1)return 0;
    for(int i = 2;i<=sqrt(num);i++)
        if(num % i == 0)
            return 0;
    return 1;
}
int main()
{
    int num,n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&num);
        if(isPrime(num))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}