#include<bits/stdc++.h>
using namespace std;
int min_subset_sum_diff(int a[],int n,int sum)
{   vector<int>v ;
int mn=INT_MAX;
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    for(int j=0;j<sum+1;j++)
    {
        if(i==0)
        t[i][j]=false;
        if(j==0)
        t[i][j]=true;
    }
    for(int i=1;i<n+1;i++)
    for(int j=1;j<sum+1;j++)
    {
        if(a[i-1]<=j)
        t[i][j]=t[i-1][j]||t[i-1][j-a[i-1]];
        else
        t[i][j]=t[i-1][j];
    }
    for(int i=1;i<n+1;i++)
    for(int j=1;j<(sum+1)/2;j++)
    {
        if(i==n)
        {
            if(t[i][j]==true)
          v.push_back(j);  
        }
    }
    for(int i=0;i<v.size();i++)
    {
        mn=min(mn,sum-2*v[i]);
    }
    return mn;
}
int main()
{
    int n,range=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    {
        range=range+a[i];
    }
    cout<<min_subset_sum_diff(a,n,range);
}
