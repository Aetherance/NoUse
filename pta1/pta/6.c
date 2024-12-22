#include <stdio.h>
 
int main(){
    int num=0,a[500],n,n1;
    scanf("%d %d",&n,&n1);
    for (int i = n; i <= n1; ++i) {
        int p = 0;
        int l = 0;
        for (int j = 1; j <= i/2; ++j) {
            if(!(i%j))
            {
                a[p] = j;
                l += j;
                num++;
                p++;
            }
        }
        if(l == i){
            printf("%d its factors are ",i);
            for (int j = 0; j < num; ++j) {
                printf("%d ",a[j]);
            }
            printf("\n");
        }
        num = 0;
    }
    return 0;
}