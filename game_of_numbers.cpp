/*
  author: Taj Maun Kamal
  Hackerrank : _maun
*/
#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
LL arr[11];
map<LL,LL>mp;
/*bruteforce solution*/
bool call(LL k,LL l,LL r)
{
    int x=0;
    if(k<=0)
        return 0;
    if(mp.find(k)!=mp.end())
        return mp[k];
    for(int i=l;i<=r;i++)
    {

               int f = call(k - i,l,r);
                if(!f)
                 {
                    return mp[k]=1;
                 }

    }

    return mp[k]=0;

}
int main() {


    LL n,m;

    cin>>n;
    for(int i=0;i<n;i++)
    {
    LL x,y,z;
        cin>>x>>y>>z;
    //cout<<z<<" ";
     LL c = 0;
     int t=0;
        int f=0;
     while(c<=z)
     {
         if(!f)
         {
             c +=y;
             f +=1;
         }
         else
         {

             if(z >c && z<= c + x)
             {
               t = 1;
               break;
             }
             c +=x;
             f -=1;
         }


     }
    if(!t)
        cout<<"Alice"<<endl;
    else
        cout<<"Bob"<<endl;

    }
    return 0;
}
