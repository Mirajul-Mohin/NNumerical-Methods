#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    return exp(0.5*x)+5*x-5;
}

double func2(double x)
{
    return sin(x)+cos(1+(x*x))-1;
}

int main()
{
    double lo,hi,xo,x1,x2,xm,a,pnt,xi,x_1,xi_1;
    int step=0;
    printf("//For e^0.5x + 5x - 5\n//Initial guess (0,2)\n");
    printf("Enter accuracy: ");
    scanf("%lf",&a);
    xi_1=0, xi=2;
    printf("\nItr    X(i-1)        Xi          Xm        f(Xm)     Rel. Approx. Error\n");
    printf("------------------------------------------------------------------------\n");
    while(pnt=fabs((xi-xi_1)/xi)*100>a)
    {
        step++;
        pnt=fabs((xi-xi_1)/xi);
        double x2= xi-((func(xi)*(xi-xi_1))/(func(xi)-func(xi_1)));
        printf("%-5d%8.6lf%12.6lf%12.6lf%12.6lf%15.6lf\n",step,xi_1,xi,x2, func(x2),pnt*100);
        xi_1=xi;
        xi=x2;
    }


    printf("\n\n\n//For sin(x) + cos(1+x^2)-1\n//Initial guess (1,3)\n");
    step=0;
    xi_1=1.0, xi=3.0;

    printf("\nItr    X(i-1)        Xi          Xm        f(Xm)     Rel. Approx. Error\n");
    printf("------------------------------------------------------------------------\n");

    while(step<4)
    {
        step++;
        pnt=fabs((xi-xi_1)/xi);
        double x2= xi-((func2(xi)*(xi-xi_1))/(func2(xi)-func2(xi_1)));
        printf("%-5d%8.6lf%12.6lf%12.6lf%12.6lf%15.6lf\n",step,xi_1,xi,x2, func2(x2),pnt*100);
        xi_1=xi;
        xi=x2;
    }

    step=0;
    xi_1=1.5, xi=2.5;
    printf("\n\n//Initial guess (1.5,2.5)\n");

    printf("\nItr    X(i-1)        Xi          Xm        f(Xm)     Rel. Approx. Error\n");
    printf("------------------------------------------------------------------------\n");

    while(step<4)
    {
        step++;
        pnt=fabs((xi-xi_1)/xi);
        double x2= xi-((func2(xi)*(xi-xi_1))/(func2(xi)-func2(xi_1)));
        printf("%-5d%8.6lf%12.6lf%12.6lf%12.6lf%15.6lf\n",step,xi_1,xi,x2, func2(x2),pnt*100);
        xi_1=xi;
        xi=x2;
    }


    step=0;
    xi_1=1.5, xi=2.25;
    printf("\n\n//Initial guess (1.5,2.25)\n");

    printf("\nItr    X(i-1)        Xi          Xm        f(Xm)     Rel. Approx. Error\n");
    printf("------------------------------------------------------------------------\n");

    while(step<4)
    {
        step++;
        pnt=fabs((xi-xi_1)/xi);
        double x2= xi-((func2(xi)*(xi-xi_1))/(func2(xi)-func2(xi_1)));
        printf("%-5d%8.6lf%12.6lf%12.6lf%12.6lf%15.6lf\n",step,xi_1,xi,x2, func2(x2),pnt*100);
        xi_1=xi;
        xi=x2;
    }


}
