#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    long long int n,Min[3],Max[3],ans,i,j,k,a1,a2,a3;


    while(cin>>n)
    {
        for(i=0;i<3;i++)
            cin>>Min[i]>>Max[i];

            a1=Min[0];
            a2=Min[1];
            a3=Min[2];
            n=n-a1-a2-a3;



            if(a1<Max[0] && n!=0)
            {
                if((Max[0]-a1)<n)
                {
                     n=n-(Max[0]-a1);
                    a1=a1+(Max[0]-a1);
                  }

                   else
                   {
                       a1=a1+n;
                       n=0;
                   }
            }
            if(a2<Max[1] && n!=0)
            {
                if((Max[1]-a2)<n)
                {
                    n=n-(Max[1]-a2);
                    a2=a2+(Max[1]-a2);
                   }

                   else
                   {
                       a2=a2+n;
                       n=0;
                   }
            }

            if(n!=0)
                {a3=a3+n;
                 n=0;
                }

           cout<<a1<<" "<<a2<<" "<<a3<<endl;

    }
}
