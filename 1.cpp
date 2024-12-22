// #include<iostream>
// using namespace std;
// int main()
// {
//     int cls;
//     cin>>cls;
//     double h;
//     double m = 0;
//     int max;
//     if(cls == 1)
//     {
//         cin>>h;
//         max = h/24;
//         if(h/24 != 0)max += 1;
//         max *= 50;
//         if(h<=1)m = 5;
//         if(h>1)
//         {
//             h -= 1;
//             m += 5;
//             while(h>0)
//             {
//                 m += 2;
//                 h -= 0.5;
//             }
//         }
//         if(m>max)
//         {
//             printf("%0.2lf",(double)max);
//             return 0;
//         }
//         printf("%0.2lf",m);

//     }
//     if(cls == 2)
//     {
//         cin>>h;
//         max = h/24;
//         if(h/24 != 0)max += 1;
//         max *= 30;
//         if(h<=2)m = 5;
//         if(h>2)
//         {
//             h -= 2;
//             m += 5;
//             while(h>0)
//             {
//                 h -= 1;
//                 m += 2;
//             }
//         }
//         if(m>max)
//         {
//             printf("%0.2lf",(double)max);
//             return 0;
//         }
//         printf("%0.2lf",m);
//     }
//     if(cls == 3)
//     {
//         cin>>h;
//         max = h/24;
//         if(h/24 != 0)max += 1;
//         max *= 20;
//         int temp = h;
//         if(h<=3)m = 5;
//         if(h>3)
//         {
//             h-=24*(max - 1);    
//             m+=20*(max - 1);   
//             h -= 3;
//             m += 5;   
//             while(h>0)
//             {
//                 h-=1;
//                 m+=1;
//             }
//         }
       
//         if(m>max)
//         {
//             printf("%0.2lf",(double)max);
//             return 0;
//         }
//         printf("%0.2lf",m);
//     }


//     return 0;
// }