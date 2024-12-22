#include<stdio.h>
double li(double l)
{
    return 1609.0*l;
}
double chi(double chi)
{
    return 30.48*chi;
}
double cun(double cun)
{
    return 2.54*cun;
}
int main()
{
    double l,ch,c;
    scanf("%lf%lf%lf",&l,&ch,&c);

    printf("%.2lf %0.2lf\n",l,li(l));
    printf("%.2lf %0.2lf\n",ch,chi(ch));
    printf("%.2lf %0.2lf\n",c,cun(c));
    

    return 0;
}