#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[1000][1000];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int max=0,max1,min1;
    int count=0;
    int arr2[10000],t;
        for(int i=0;i<n;i++){
            max=arr[i][0];
            max1=0;
            arr2[0]=-1;
            t=0;
    for(int j=0;j<n;j++){
        if(max<arr[i][j]){
            max=arr[i][j];
            max1=j;
        }
        if(max==arr[i][j]){
            if(arr2[0]==-1){
                arr2[0]=max1;
                arr2[1]=j;
                t=2;
            }else{
                arr2[t++]=j;
            }
        }
}
        int min;
        if(t>0){
            for(int q=0;q<t;q++){
                min=arr[i][arr2[q]];
                for(int k=0;k<n;k++){
                    if(min>arr[k][arr2[q]]){
                        min=arr[k][arr2[q]];
                        break;
                    }
                }
    if(max==min){
        max1=arr2[q];
        count++;
        printf("%d %d\n",i,max1);
        break;
    }
}
        }else{
            min=arr[i][max1];
            for(int k=0;k<n;k++){
                if(min>arr[k][max1]){
                    min=arr[k][max1];
                    break;
                }
            }
            if(max==min){
                count++;
                printf("%d %d\n",i,max1);
                break;
            }
        }
    }
    
    
    
    if(count==0){
        printf("NONE\n");
    }
    return 0;
}