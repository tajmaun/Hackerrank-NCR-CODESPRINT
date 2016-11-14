/*
  author: Taj Maun Kamal
  Hackerrank : _maun
*/
#include<bits/stdc++.h>
using namespace std;
#define LL long long
# define MAX_SIZE 100
LL f=0;
LL mod=1e9 + 7;
int dp[200][200][3][100];
LL solve(int pos, int n, int open, int close,int k,int s,int h)
{
    LL x=0,y=0;
    if(dp[open][close][s][h]!=-1)
        return dp[open][close][s][h];

    if(close == n)
    {
        // cout<<h<<endl;
        if(h>=k)
            return 1;
        return 0;
    }
    else
    {

        if(open > close)
        {
            x =solve(pos+1, n, open, close+1,k,1,s!=0 && s!=1 ? h + 1 : h + 0);
        }
        if(open < n)
        {
            y =solve(pos+1, n, open+1, close,k,2,s!=0 && s!=2 ? h + 1 : h + 0);
        }
    }
    //cout<<open<<close<<s<<" "<<h<<" "<<(x+y)%mod<<endl;
    return  dp[open][close][s][h]=(x+y)%mod;
}
void call(int n,int k)
{
    if(n > 0)
        cout<< solve(0, n, 0, 0,k,0,0)<<endl;
    f=0;
    return;
}


int main()
{
    int c;
    cin>>c;
    for(int i=0; i<c; i++)
    {
        memset(dp,-1,sizeof(dp));
        int n,k;
        cin>>n>>k;
        n=n/2;
//for(int i=1;i<=k;i++)
        call(n,k);
    }
    return 0;
}
