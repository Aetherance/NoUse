#include<stdio.h>
void func()
{




}
int main()
{
    FILE * fp = fopen("./e.txt","r");
    char ch[10];
    fscanf(fp,"\n%[^\n]",ch);
    printf("%s\n",ch);
    fscanf(fp,"\n%[^\n]",ch);
    printf("%s\n",ch);
    fscanf(fp,"\n%[^\n]",ch);
    printf("%s\n",ch);
    fscanf(fp,"\n%[^\n]",ch);
    printf("%s\n",ch);
    fscanf(fp,"\n%[^\n]",ch);
    printf("%s\n",ch);
    fscanf(fp,"\n%[^\n]",ch);
    printf("%s\n",ch);
}