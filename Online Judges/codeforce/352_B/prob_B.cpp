#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double dis(double x1,double y1, double x2, double y2)
{

    double z;

    z= sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

    return z;


}







    double arr[500000][3];
    double arr1[500000][3];

int main()
{

    long long n;

    double x1,y1,x2,y2,x3,y3;

    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;



    cin>>n;

    for(int i=1 ; i<=n ;i++)
    {
        cin>>arr[i][0];
        arr1[i][0]=arr[i][0];
        cin>>arr[i][1];
        arr1[i][1]=arr[i][0];
    }



    int pos=0;

    double md=1000000000000;

    for(int i=1 ; i<=n ;i++)
    {
        if(dis(x1,y1,arr[i][0],arr[i][1])+dis(arr[i][0],arr[i][1],x3,y3)<md)
        {
            md=dis(x1,y1,arr[i][0],arr[i][1])+dis(arr[i][0],arr[i][1],x3,y3);
            pos=i;
        }
    }


    double md1=100000000000000;
    int pos1=0;
    {

          for(int i=1 ; i<=n ;i++)
    {
        if(dis(x2,y2,arr[i][0],arr[i][1])+dis(arr[i][0],arr[i][1],x3,y3)<md)
        {
            md1=dis(x2,y2,arr[i][0],arr[i][1])+dis(arr[i][0],arr[i][1],x3,y3);
            pos1=i;
        }
    }

    }



    double md3=100000000000000000;
    double md4=100000000000000000;

    if(md1==md)
    {

          for(int i=1 ; i<=n ;i++)
        {
        if(i==pos)
            continue;

        if(dis(x1,y1,arr[i][0],arr[i][1])+dis(arr[i][0],arr[i][1],x3,y3)<md)
        {
            md3=dis(x1,y1,arr[i][0],arr[i][1])+dis(arr[i][0],arr[i][1],x3,y3);

        }
        }



          for(int i=1 ; i<=n ;i++)
       {
        if(i==pos1)
            continue;
        if(dis(x2,y2,arr[i][0],arr[i][1])+dis(arr[i][0],arr[i][1],x3,y3)<md)
        {
            md4=dis(x2,y2,arr[i][0],arr[i][1])+dis(arr[i][0],arr[i][1],x3,y3);

        }
       }

       if(md3>md4)
        md1+=1;
       else
        md+=1;

    }

    bool flag=0;


    double td=0;


    if(md<md1)
    {
        arr[pos][2]=11;

        td+=md;

        for(int i=1; i<=n ;i++)
        {

            if(pos==i)
                continue;


        if(flag==0)
        {
            if( dis(x2,y2,arr[i][0],arr[i][1])+dis(arr[i][0],arr[i][1],x3,y3) < 2*dis(x3,y3,arr[i][0],arr[i][1]) )
            {
                flag=1;
                td+=dis(x2,y2,arr[i][0],arr[i][1])+dis(arr[i][0],arr[i][1],x3,y3);
            }
            else
                td+=2*dis(x3,y3,arr[i][0],arr[i][1]);

        }
        else
        {
             td+=2*dis(x3,y3,arr[i][0],arr[i][1]);
        }

        }



    }

    else
    {

        td+=md1;

        for(int i=1; i<=n ;i++)
        {

            if(pos1==i)
                continue;


        if(flag==0)
        {
            if( dis(x1,y1,arr[i][0],arr[i][1])+dis(arr[i][0],arr[i][1],x3,y3) < 2*dis(x3,y3,arr[i][0],arr[i][1]) )
            {
                flag=1;
                td+=dis(x1,y1,arr[i][0],arr[i][1])+dis(arr[i][0],arr[i][1],x3,y3);
            }
            else
                td+=2.000000*dis(x3,y3,arr[i][0],arr[i][1]);

        }
        else
        {
              td+=2.000000000*dis(x3,y3,arr[i][0],arr[i][1]);
        }

        }

    }

    printf("%.10lf\n",td);




    return 0;

}

