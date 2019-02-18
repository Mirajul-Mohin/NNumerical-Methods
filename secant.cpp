
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
//    return 3*(x-1)*(x-1);
//}
//
//int main()
//{
//    double lo,hi,xo,x1,x2,xm,a,pnt,xi,x_1;
//    int step=0;
//    printf("Enter Xo, X1, accr: ");
//    scanf("%lf %lf %lf",&xo,&x1,&a);
//    printf(" Itr       X(i-1)              Xi                 X(i+1)              f(x+1)             Rel. Approx. Error\n");
//    printf("---------------------------------------------------------------------------------------------------\n");
//    while(pnt=fabs((x1-xo)/x1)>a)
//    {
//        step++;
//        //xo=x1;
//        pnt=fabs((x1-xo)/x1);
//        x2= x1-((func(x1)*(x1-xo))/(func(x1)-func(xo)));
//        x_1=xo;
//        xo=x1;
//        x1=x2;
//        printf("  %d        %lf         %lf         %lf             %lf           %lf \n",step,x_1,xo,x1, func(x1),pnt*100);
//
//
//    }
//
//}


//For (x-4)^2(x+2)

#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    return (x-4)*(x-4)*(x+2);
}

double d_func(double x)
{
    return 3*(x-1)*(x-1);
}

int main()
{
    double lo,hi,xo,x1,x2,xm,a,pnt,xi,x_1;
    int step=0;
    printf("Enter Xo, X1, accr: ");
    scanf("%lf %lf %lf",&xo,&x1,&a);
    printf(" Itr       X(i-1)              Xi                 X(i+1)              f(x+1)             Rel. Approx. Error\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    while(pnt=fabs((x1-xo)/x1)>a)
    {
        step++;
        //xo=x1;
        pnt=fabs((x1-xo)/x1);
        x2= x1-((func(x1)*(x1-xo))/(func(x1)-func(xo)));
        x_1=xo;
        xo=x1;
        x1=x2;
        printf("  %d        %lf         %lf         %lf             %lf           %lf \n",step,x_1,xo,x1, func(x1),pnt*100);


    }

}
