#define pi 3.1415926
#include<stdio.h>
#include<math.h>

int main()
{
    double a,b;
    double degrees,minutes,seconds;
    scanf("%lf%lf",&a,&b);
    scanf("%lf%lf%lf",&degrees,&minutes,&seconds);
    double xita = degrees + (minutes / 60.0) + (seconds / 3600.0);
    a = a * tan(xita*pi/180.0);

    printf("%0.2lf",a+b);


    return 0;
}