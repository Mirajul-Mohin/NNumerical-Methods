#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    return pow(x,100);
}

double d_func(double x)
{
    return 100*pow(x,99);
}

double func2(double x)
{
    return 3*pow(x,1.0/3.0);
}

double d_func2(double x)
{
    return pow(x,-2.0/3.0);
}

int main()
{
    double lo,hi,xo,xm,a,pnt,xi;
    int step=0;

    printf("                          Newton-Raphson\nFor x^100=0\n");
    xi=.1;
    a=.00001;
    printf("\n   Itr        Xi            f(Xi)           f'(Xi)    Rel. Approx. Error\n");
    printf("----------------------------------------------------------------------\n");
    while(step<5)
    {
        step++;
        pnt=fabs((xi-xo)/xi)*100;
        printf("%5d%15.6lf%15.6lf%15.6lf%15.6lf\n",step,xi,func(xi),d_func(xi),pnt);
        xo=xi;
        xi= xi-(func(xi)/d_func(xi));
    }

    printf("\n\nFor 3x^(1/3)=0\n");
    xi=.1,xo=0;
    step=0;
    a=.00001;
    printf("\n   Itr        Xi            f(Xi)           f'(Xi)    Rel. Approx. Error\n");
    printf("----------------------------------------------------------------------\n");
    while(step<10)
    {
        step++;
        pnt=fabs((xi-xo)/xi)*100;
        printf("%5d%15.6lf%15.6lf%15.6lf%15.6lf\n",step,xi,func2(xi),d_func2(xi),pnt);
        xo=xi;
        xi= xi-(func2(xi)/d_func2(xi));
    }

}
