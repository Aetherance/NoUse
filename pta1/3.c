#include<stdio.h>
int arr[1000][1000] = {};
int main()
{
    int n;
    

    arr[1][1] = 1;
    arr[2][1] = 1;
    arr[2][2] = 1;

    for(int i = 1;i<=100;i++)
        for(int j = 1;j<=100;j++)
        {
            if(i==1&&j==1)continue;
            arr[i][j] = arr[i-1][j] + arr[i-1][j-1]; 
        }

    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 1;i<=n;i++)
        {
                for(int j = 1;j<=n;j++)
                {
                    if(arr[i][j]!=0)printf("%5d",arr[i][j]);
                }
            printf("\n");
        }
    }
    return 0;
}