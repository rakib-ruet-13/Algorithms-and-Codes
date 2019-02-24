#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    deque<int>dek;
    int tc;
    scanf("%d",&tc);

    for(int cs=1;cs<=tc;cs++)
    {
        int s,n;
        scanf("%d %d",&s,&n);
        getchar();

        string str;
        int val;
        printf("Case %d:\n",cs);

        for(int i=0;i<n;i++)
        {
           cin>>str;

           if(str=="pushLeft" || str=="pushRight")
           {
               cin>>val;
               if(dek.size()==s)
                cout<<"The queue is full"<<endl;
               else
               {
                   if(str=="pushLeft")

                   {
                       printf("Pushed in left: %d\n",val);
                       dek.push_front(val);
                   }
                   else
                   {
                        printf("Pushed in right: %d\n",val);
                        dek.push_back(val);

                   }

               }

           }
           else
           {
                if(dek.empty())
                {
                    printf("The queue is empty\n");
                }
                else
                {
                    if(str=="popLeft")
                    {
                        printf("Popped from left: %d\n",dek.front());
                        dek.pop_front();
                    }
                    else
                    {
                        printf("Popped from right: %d\n",dek.back());
                        dek.pop_back();
                    }
                }
           }
        }
        dek.clear();
    }



    return 0;

}
