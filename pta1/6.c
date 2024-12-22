#include<stdio.h>
int arr[1000][1000];
int main()

{
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            scanf("%d",&arr[i][j]);

    int x_max[100],y_min[100];

    int x_max_l = 0,y_min_l = 1000000;

    int x_c = 0,y_c = 0;

    int x[100],y[100];

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(arr[i][j]>x_max_l)
            {
                x_max[x_c] = arr[i][j];
                x[x_c++] = i;
            }
        }
    }
    
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(arr[i][j]<y_min_l)
            {
                y_min[y_c] = arr[i][j];
                y[y_c++] = j;
            }
        }
    }
    int r1x = -1,r2y = -1;
    for(int i = 0;i<x_c;i++)
    {
        for(int j = 0;j<y_c;j++)
        {
            if(x_max[i]==y_min[j])
            {
                r1x = i;
                r2y = j;
            }
        }
    }

    if(r1x == -1)
    {
        printf("NONE");
        return 0;
    }

    printf("%d %d",r1x,r2y);
    
    return 0;
}
