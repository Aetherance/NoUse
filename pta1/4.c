#include<stdio.h>
int arr[10000][10000];
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i = 0;i<m;i++)
    {
        int py,px,max = 0;
        for(int j = 0;j<n;j++)
        {
            if(arr[i][j]>max)
            {
                max = arr[i][j];
                py = i;
                px = j;
            }
        }
        printf("%d %d %d\n",max,py+1,px+1);
    }




    return 0;
}