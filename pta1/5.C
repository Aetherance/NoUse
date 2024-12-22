#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int N;
    scanf("%d",&N);
    char str[1000][1000];
    char ID[100];
    char max_id[3][100];
    int count = 0;
    int max[3];

    int c_1 = 0;
    int c_2 = 0;
    for(int i = 0;i<N;i++) 
    {
        scanf("%s",ID);
        scanf("\n%[^\n]",str[i]);
        for(int j = 0;j<strlen(str[i]);j++)
        {
            if(str[i][j]>='A'&&str[i][j]<='Z')str[i][j]+=32;
        }
        char * temp = str[i];
        if(strstr(temp,"chatgpt") != NULL)count++;
        while(strstr(temp,"chatgpt") != NULL)
        {
            count++;
            temp = strstr(temp,"chatgpt") + 1;   
        }
        if(count>max[c_2-1])
        {
            strcpy(max_id[c_1++],ID);
            max[c_2++] = count;
        }

        count = 0;
    }
    

    printf("%s ",max_id[2]);
    printf("%d\n",max[2]);

    printf("%s ",max_id[1]);
    printf("%d\n",max[1]);
    
    printf("%s ",max_id[0]);
    printf("%d\n",max[0]);

    return 0;
}