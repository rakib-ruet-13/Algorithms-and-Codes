#include<stdio.h>
#include<math.h>
int main()
{
    double vol;
    long int l,w,h,ang;
    printf("\n");
    while(scanf("%d %d %d %d",&l,&w,&h,&ang)==4)
    {
        vol=l*w*(h-(.5*l*(tan(ang*cos(2.0)/180))));
        printf("%.3lf mL\n\n",vol);

    }
    return 0;
}
