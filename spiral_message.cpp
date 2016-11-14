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
int vis[100][100];
int R,C;

int spiralPrint(int m, int n, vector<string>a)
{
    int i, k = 0, l = 0;

    int d=0,f=0;

    while (k < m && l < n)
    {

        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
            //   printf("%c ", a[i][l]);

                if((isupper(a[i][l]) || islower(a[i][l])) && !vis[i][l])
                {
                    f++;
                }
                else if(a[i][l]=='#' && !vis[i][l])
                {
                    if(f)
                        d++;
                    f=0;
                }
                vis[i][l]++;

            }
            l++;
        }
        for (i = l; i < n; ++i)
        {


                if((isupper(a[k][i]) || islower(a[k][i])) && !vis[k][i])
                {
                    f++;
                }
                else if(a[k][i]=='#' && !vis[k][i])
                {
                    if(f)
                        d++;
                    f=0;
                }
                vis[k][i]++;
        }
        k++;


        for (i = k; i < m; ++i)
        {


           if((isupper(a[i][n-1]) || islower(a[i][n-1])) && !vis[i][n-1])
                {
                    f++;
                }
                else if(a[i][n-1]=='#' && !vis[i][n-1])
                {
                    if(f)
                        d++;
                    f=0;
                }
                vis[i][n-1]++;
        }
        n--;


        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {


               if((isupper(a[m-1][i]) || islower(a[m-1][i])) && !vis[m-1][i])
                {
                    f++;
                }
                else if(a[m-1][i]=='#' && !vis[m-1][i])
                {
                    if(f)
                        d++;
                    f=0;
                }
                vis[m-1][i]++;
            }
            m--;
        }

    }
    if(f)
        d++;
    return d;
}
int main()
{


        int x,y;
        cin>>x>>y;
        vector<string>v;

        for(int j=0; j<x; j++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }

       cout<< spiralPrint(x,y,v)<<endl;



}
