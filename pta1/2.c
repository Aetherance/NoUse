#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int __count = 1;
void go(char ch_p[1000000],char*p,char str_p[1000000],int len)
{
	char* pp = strstr(p-1 + len, str_p);
	if (pp == NULL)return;
	__count++;
	go(ch_p, pp, str_p,len);
}
int main()
{
	char str[1000000],ch[1000000];
	scanf("%[^\n]\n",str);
    scanf("%[^\n]",ch);
	int temp = 0;
	while (str[temp++]!='\0')
	{
		if (str[temp-1] < 97 && str[temp-1] >= 65)str[temp-1] += 32;
	}

	temp = 0;
	while (ch[temp++] != '\0')
	{
		if (ch[temp - 1] < 97 && ch[temp - 1] >= 65)ch[temp - 1] += 32;
	}

	char str_p[1000000];
	sprintf(str_p, " %s ", str);
	char ch_p[1000000];
	sprintf(ch_p, " %s ", ch);
	char* p = strstr(ch_p, str_p);
	int len = strlen(str_p);
	if (p != NULL)
	{
		go(ch_p, p,str_p,len);
		printf("%d ", __count);
		printf("%d", (int)(p - ch_p));
	}
	if (p == NULL)printf("-1");

	return 0;
}