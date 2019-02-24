#include<bits/stdc++.h>

using namespace std;


struct node
{
    double x;
    double y;

};
int main()
{
    int n;
    double r;
    cin>>n>>r;

    vector<node>vct;



    for(int i=0; i<n ; i++)
    {
        node temp;

        cin>>temp.x;
        temp.y=0;

        if(i==0)
        {
            temp.y=r;
        }
        else
        {

            node temp2;
            bool flag=0;
            for(int i=0; i<vct.size(); i++)
            {

                double ll=temp.x-r;
                double rr=temp.x+r;

                if( !(vct[i].x-r> rr || vct[i].x+r<ll))
                {
                    temp2=vct[i];
                    temp.y=max(temp.y,temp2.y+sqrt(4*r*r-(temp.x-temp2.x)*(temp.x-temp2.x)));
                    flag=1;

                }
            }

            if(flag==0)
            {
                temp.y=r;
            }


        }
        vct.push_back(temp);




    }

    for(int i=0; i<vct.size() ; i++)
    {
        if(i==0)
        printf("%.10f",vct[i].y);
        else
         printf(" %.10f",vct[i].y);

    }
    cout<<endl;






    return 0;
}
