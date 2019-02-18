
 //For x^3 - 0.165x^2 + 3.993*10^-4

//#include<bits/stdc++.h>
//using namespace std;
//
//double func(double x)
//{
//    return pow(x,3)-0.165*x*x+(3.993*pow(10,-4));
//}
//
//double d_func(double x)
//{
//    return 3*pow(x,2)-.33*x;
//}
//
//int main()
//{
//    double lo,hi,xo,xm,a,pnt,xi;
//    int step=0;
//    printf("Give Input: ");
//    scanf("%lf %lf",&xi,&a);
//    printf(" Itr     Xi          f(Xi)           f'(Xi)          Rel. Approx. Error\n");
//    printf("----------------------------------------------------------------------------\n");
//    while(fabs((xi-xo)/xi)>a)
//    {
//        step++;
//        pnt=fabs((xi-xo)/xi)*100;
//        printf("  %d    %lf       %lf       %lf      %lf \n",step,xi,func(xi),d_func(xi),pnt);
//        xo=xi;
//        xi= xi-(func(xi)/d_func(xi));
//    }
//
//}






// For (x-1)^3+0.512

//#include<bits/stdc++.h>
//using namespace std;
//
//double func(double x)
//{
//    return pow(x-1,3)+.512;
//}
//
//double d_func(double x)
//{
//    return 3*(x-1)*(x-1);
//}
//
//int main()
//{
//    double lo,hi,xo,xm,a,pnt,xi;
//    int step=0;
//    printf("Give Input: ");
//    scanf("%lf %lf",&xi,&a);
//    printf(" Itr    Xi                    f(Xi)                   f'(Xi)                   Rel. Approx. Error\n");
//    printf("---------------------------------------------------------------------------------------------------\n");
//    while(step<=17)
//    {
//        step++;
//        pnt=fabs((xi-xo)/xi)*100;
//        printf("  %d        %lf              %lf             %lf           %lf \n",step,xi,func(xi),d_func(xi),pnt);
//        xo=xi;
//        xi= xi-(func(xi)/d_func(xi));
//    }
//
//}


//For (x-4)^2 (x+2)


#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    return (x-4)*(x-4)*(x+2);
}

double d_func(double x)
{
    return 2*(x+2)*(x-4)+(x-4)*(x-4);
}

int main()
{
    double lo,hi,xo,xm,a,pnt,xi;
    int step=0;
    printf("Give Input: ");
    scanf("%lf %lf",&xi,&a);
    printf(" Itr    Xi                    f(Xi)                   f'(Xi)                   Rel. Approx. Error\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    while(fabs((xi-xo)/xi)>a)
    {
        step++;
        pnt=fabs((xi-xo)/xi)*100;
        printf("  %d        %lf              %lf             %lf           %lf \n",step,xi,func(xi),d_func(xi),pnt);
        xo=xi;
        xi= xi-(func(xi)/d_func(xi));
    }

}





