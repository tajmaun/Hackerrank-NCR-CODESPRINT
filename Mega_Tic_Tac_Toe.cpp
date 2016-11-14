/*
  author: Taj Maun Kamal
  Hackerrank : _maun
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int min(int a, int b)
{ return (a < b)? a: b; }


int min(int a, int b, int c)
{ return min(min(a, b), c);}

int max(int a, int b)
{ return (a > b)? a: b; }
int main()
{

    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        vector<string>v;
        for(int i=0; i<x; i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
        int t=1,f=1;;
        for(int i=0; i<x; i++)
        {
            int d=1;
            for(int j=1; j<v[i].size(); j++)
            {
                if(v[i][j] == 'O' && v[i][j-1]=='O')
                    d++;
                else
                    d=1;
                if(d==z)
                {
                    t=0;
                }

            }
            d=1;
            for(int j=1; j<v[i].size(); j++)
            {
                if(v[i][j] == 'X' && v[i][j-1]=='X')
                    d++;
                else
                    d=1;
                if(d==z)
                {
                    f=0;
                }

            }
        }
        for(int i=0; i<y; i++)
        {
            int d=1;
            for(int j=1; j<x; j++)
            {
                if(v[j][i] == 'O' && v[j-1][i]=='O')
                    d++;
                else
                    d=1;
                if(d==z)
                {
                    t=0;

                }

            }
            d=1;
            for(int j=1; j<x; j++)
            {
                if(v[j][i] == 'X' && v[j-1][i]=='X')
                    d++;
                else
                    d=1;
                if(d==z)
                {
                    f=0;
                }

            }
        }
        vector<string>V;
        for(int i=0;i<v.size();i++)
        {
            string S="";
              for(int j=y-1;j>=0;j--)
                S+=v[i][j];
            V.push_back(S);
        }
        // There will be ROW+COL-1 lines in the output
        for (int line=1; line<=(x + y -1); line++)
        {

            int start_col =  max(0, line-x);


            int count = min(line, (y-start_col), x);
            string s="",S="";

            for (int j=0; j<count; j++)
                s+=v[min(x, line)-j-1][start_col+j];
            for (int j=0; j<count; j++)
                S+=V[min(x, line)-j-1][start_col+j];
            int d=1,dt=1;
            for(int j=1; j<s.size(); j++)
            {

                if(s[j] == 'X' && s[j-1]=='X')
                    d++;
                else
                    d=1;
                if(d==z)
                {
                    f=0;
                }
                if(s[j] == 'O' && s[j-1]=='O')
                    dt++;
                else
                    dt=1;
                if(dt==z)
                {
                    t=0;
                }
            }
            d=dt=1;
            for(int j=1; j<S.size(); j++)
            {

                if(S[j] == 'X' && S[j-1]=='X')
                    d++;
                else
                    d=1;
                if(d==z)
                {
                    f=0;
                }
                if(S[j] == 'O' && S[j-1]=='O')
                    dt++;
                else
                    dt=1;
                if(dt==z)
                {
                    t=0;
                }
            }


        }
        if(!t && f)
            cout<<"WIN"<<endl;
        else if(!f && t)
            cout<<"LOSE"<<endl;
        else
            cout<<"NONE"<<endl;

    }
    return 0;
}
