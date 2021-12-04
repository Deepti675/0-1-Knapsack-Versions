#include <bits/stdc++.h>
using namespace std;
bool subset_sum(int a[],int n,int sum)
{
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    for(int j=0;j<sum+1;j++)
    {
        if(i==0)
        t[i][j]=false;
        if(j==0)
        t[i][j]=true;
    }
    if(sum%2!=0)
    return false;
    else
    {
    for(int i=1;i<n+1;i++)
    for(int j=1;j<sum+1;j++)
    {
        if(a[i-1]<=j)
        t[i][j]=t[i-1][j-a[i-1]]||t[i-1][j];
        else
        t[i][j]=t[i-1][j];
    }
    }
    return t[n][sum];
    
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int sum=0;
    for(int i=0;i<n;i++)
    sum=sum+a[i];
    cout<<subset_sum(a,n,sum);


    return 0;
}
