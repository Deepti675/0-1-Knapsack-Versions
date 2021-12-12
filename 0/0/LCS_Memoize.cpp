//memoize code *****************
#include <bits/stdc++.h>

using namespace std;
int static t[1001][1001];
int LCS(string x,string y,int n,int m)
{
    if(n==0||m==0)
    return 0;
    if(t[m][n]!=-1)
    return t[m][n];
    if(x[n-1]==y[m-1])
    {
    t[m][n]=1+LCS(x,y,n-1,m-1);
    return t[m][n];
    }
    else
    {
    t[m][n]=max(LCS(x,y,n,m-1),LCS(x,y,n-1,m));
    return t[m][n];
    }
}
int main()
{
    string x,y;
    cin>>x>>y;
    int n= x.size();
    int m= y.size();
    //cout<<m<<" "<<n;
    memset(t,-1,sizeof(t));
    cout<<LCS(x,y,n,m);
    return 0;
}
