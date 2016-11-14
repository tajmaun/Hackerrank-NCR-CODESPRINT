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


int main() {
   int n,m=0;
    cin>>n;
    int s[n+1];
    for(int i=0;i<n;i++)
        cin>>s[i];
    if(s[0]!=1)
        m++;
    for(int i=1;i<n;i++)
    {
       if(s[i] != s[i-1] + 1)
           m++;
    }
    cout<<m<<endl;
    return 0;
}
