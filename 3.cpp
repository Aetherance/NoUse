// #include<stdio.h>
// int main()
// {
//     double x,y;
//     char sign;
//     FLAG:
//     scanf("%lf%c%lf",&x,&sign,&y);
//     printf("%lf%c%lf=",x,sign,y);
//     switch (sign)
//     {
//     case '+':
//         printf("%lf",x+y);
//         break;
//     case '-':
//         printf("%lf",x-y);
//         break;
//     case '*':
//         printf("%lf",x*y);
//         break;
//     case '/':
//         printf("%lf",x/y);
//         break;
//     default:
//         break;
//     }

//     printf("go?(y/n)");
//     char isgo;
//     scanf("%c",&isgo);
//     if(isgo == 'y')goto FLAG;

//     return 0;
// }