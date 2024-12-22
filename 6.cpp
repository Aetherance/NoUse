#include<iostream>
using namespace std;
int main()
{
float h, mon;
int m;
cin>>m>>h;
int d = ((int)h / 24);
float time_s = h - d * 24;
if (m == 1)
{
if (time_s == 0)
{
mon = 0;
}
else if (time_s <= 1)
{
mon = 5;
}
else
{
mon = 5 + 4 * (time_s - 1);
}
if (mon > 50)
{
mon = 50;
}
mon += d * 50;
}
else if (m == 2)
{
if (time_s == 0)
{
mon = 0;
}
else if (time_s <= 2)
{
mon = 5;
}
else
{
mon = 5 + 2 * (time_s - 2);
}
if (mon > 30)
{
mon = 30;
}
mon += (d * 30);
}
else if (m == 3)
{
if (time_s == 0)
{
mon = 0;
}
else if (time_s <= 3)
{
mon = 5;
}
else
{
mon = 5 + time_s - 3;
}
if (mon > 20)
{
mon = 20;
}
mon += d * 20;
}
printf("%.2f", mon);
return 0;
}