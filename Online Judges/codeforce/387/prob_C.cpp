#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int x,y,z;
    node(int a,int b,int c)
    {
        x=a;
        y=b;
        z=c;
    }


};


  bool operator<(node a,node b)
    {
        if(a.x==b.x)
            if(a.y==b.y)
               return a.z<b.z;
            else
                return a.y<b.y;
        else
            return a.x<b.x;
    }

int main()
{

    set<node>st;

    set<node> :: iterator it,it1;

    node p(2,3,4);
    st.insert(p);

    st.insert(node(1,4,5));
    st.insert(node(4,4,8));
     st.insert(node(4,4,5));
      st.insert(node(4,4,8));
       st.insert(node(4,4,4));
        st.insert(node(4,4,4));
         st.insert(node(4,4,4));
          st.insert(node(4,4,4));

        st.insert(node(4,3,5));
      st.insert(node(4,1,5));
       st.insert(node(4,2,5));

    cout<<st.count(p)<<endl;
     it=st.upper_bound(node(100,2,4));


     //it1=st.begin();
    cout<<it->x<<" "<<it->y<<" "<< it->z<<endl;


       it=st.lower_bound(node(100,3,4));


     //it1=st.begin();
    cout<<it->x<<" "<<it->y<<" "<< it->z<<endl;


       it=st.find(node(100,3,4));


     //it1=st.begin();
    cout<<it->x<<" "<<it->y<<" "<< it->z<<endl;


    vector<int>s;
    cout<<s.begin()-s.end()<<endl;

    //cout<<pk<<endl;
    cout<<"inside"<<endl;
    for(it=st.begin() ; it!=st.end() ;it++)
    {
        cout<<it->x<<" "<<it->y<<" "<< it->z<<endl;
    }


}
